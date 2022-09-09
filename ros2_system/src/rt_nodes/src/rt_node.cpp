#include "rt_nodes/rt_node.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <rt_msgs/msg/detail/rt_header__struct.hpp>
#include <string>

using namespace std::chrono_literals;
using namespace std::placeholders;

RTNode::RTNode(std::string name) : rclcpp::Node(name){
    this->name = name;
}

RTNode::~RTNode(){
}

// Add sensor callbacks to node
void RTNode::addSensor(double period, long wcet, int bufferSize, std::string pubTopic){
    publishers.push_back(this->create_publisher<rt_msgs::msg::RTHeader>(pubTopic,bufferSize));
    int pubIndex = publishers.size()-1;
    registers.push_back(RTRegister());
    int registerIndex = registers.size()-1;
    std::string identifier = "("+this->name+" timer->"+pubTopic+")";
    timers.push_back(this->create_wall_timer(std::chrono::milliseconds((int)period), [this,wcet,pubIndex,registerIndex,identifier](){sensorCallback(wcet,pubIndex,registerIndex,identifier);}));
}

// Add filter callbacks to node
void RTNode::addFilter(long wcet, int bufferSize, std::string subTopic, std::string pubTopic){
    publishers.push_back(this->create_publisher<rt_msgs::msg::RTHeader>(pubTopic,bufferSize));
    int pubIndex = publishers.size()-1;
    registers.push_back(RTRegister());
    int registerIndex = registers.size()-1;
    std::string identifier = "("+this->name+" "+subTopic+"->filter->"+pubTopic+")";
    subscribers.push_back(this->create_subscription<rt_msgs::msg::RTHeader>(subTopic, bufferSize, [this,wcet,pubIndex,registerIndex,identifier](const rt_msgs::msg::RTHeader::SharedPtr msg){filterCallback(wcet, pubIndex, registerIndex, msg, identifier);}));
}

// Add timer fusion callbacks to node
void RTNode::addTimerFusion(std::vector<long> wcets, std::vector<int> bufferSizes, std::vector<std::string> subTopics, double period, long wcet, int bufferSize, std::string pubTopic){
    std::vector<rt_msgs::msg::RTHeader> forwardVector;
    fusionBuffer.push_back(forwardVector);
    int fusionBufferIndex = fusionBuffer.size()-1;

    for(int i = 0;i<wcets.size();i++){
        registers.push_back(RTRegister());  
        int registerIndex = registers.size()-1;
        std::string identifier = "("+this->name+" "+subTopics[i]+"->timerfusion->)";
        subscribers.push_back(this->create_subscription<rt_msgs::msg::RTHeader>(subTopics[i], bufferSizes[i], [this,tmpwcet = wcets[i],registerIndex,identifier, fusionBufferIndex](const rt_msgs::msg::RTHeader::SharedPtr msg){timerFusionSubscriberCallback(tmpwcet,registerIndex,msg,identifier,fusionBufferIndex);}));
    }
    publishers.push_back(this->create_publisher<rt_msgs::msg::RTHeader>(pubTopic,bufferSize));
    int pubIndex = publishers.size()-1;
    registers.push_back(RTRegister());
    int registerIndex = registers.size()-1;
    std::string identifier = "("+this->name+" ->timerfusion->"+pubTopic+")";
    timers.push_back(this->create_wall_timer(std::chrono::milliseconds((int)period), [this,wcet,pubIndex,registerIndex,identifier,fusionBufferIndex](){timerFusionTimerCallback(wcet,pubIndex,registerIndex,identifier,fusionBufferIndex);}));
}

// Add subscription fusion callbacks to node
void RTNode::addSubscriptionFusion(std::vector<long> wcets, std::vector<int> bufferSizes, std::vector<std::string> subTopics, std::string pubTopic){

    std::vector<rt_msgs::msg::RTHeader> forwardVector;
    fusionBuffer.push_back(forwardVector);
    int fusionBufferIndex = fusionBuffer.size()-1;
    
    for(int i = 1;i<wcets.size();i++){
        registers.push_back(RTRegister());  
        int registerIndex = registers.size()-1;
        std::string identifier = "("+this->name+" "+subTopics[i]+" ->subscriptionfusion->)";
        subscribers.push_back(this->create_subscription<rt_msgs::msg::RTHeader>(subTopics[i], bufferSizes[i], [this,wcet = wcets[i],registerIndex,identifier,fusionBufferIndex](const rt_msgs::msg::RTHeader::SharedPtr msg){subscriptionFusionSubscriberCallback(wcet,registerIndex,msg,identifier,fusionBufferIndex);}));
    }

    publishers.push_back(this->create_publisher<rt_msgs::msg::RTHeader>(pubTopic,bufferSizes[0]));
    int pubIndex = publishers.size()-1;
    registers.push_back(RTRegister());
    int registerIndex = registers.size()-1;
    std::string identifier = "("+this->name+" ->subscriptionfusion->"+pubTopic+")";
    subscribers.push_back(this->create_subscription<rt_msgs::msg::RTHeader>(subTopics[0], bufferSizes[0], [this,wcet = wcets[0],pubIndex,registerIndex,identifier,fusionBufferIndex](const rt_msgs::msg::RTHeader::SharedPtr msg){subscriptionFusionTriggerCallback(wcet,pubIndex,registerIndex,msg,identifier,fusionBufferIndex);}));


}

// Add timer actuator callbacks to node
void RTNode::addTimerActuator(long subWCET, int subBufferSize, std::string subTopic, double timerPeriod, long timerWCET, int timerBufferSize){

    std::vector<rt_msgs::msg::RTHeader> forwardVector;
    
    fusionBuffer.push_back(forwardVector);
    int fusionBufferIndex = fusionBuffer.size()-1;

    registers.push_back(RTRegister());
    int subRegisterIndex = registers.size()-1;
    std::string subIdentifier = "("+this->name+" "+subTopic+"->timeractuator->)";
    subscribers.push_back(this->create_subscription<rt_msgs::msg::RTHeader>(subTopic, subBufferSize, [this,subWCET,subRegisterIndex,subIdentifier,fusionBufferIndex](const rt_msgs::msg::RTHeader::SharedPtr msg){timerActuatorSubscriptionCallback(subWCET,subRegisterIndex,msg,subIdentifier,fusionBufferIndex);}));


    registers.push_back(RTRegister());
    int timerRegisterIndex = registers.size()-1;
    std::string timerIdentifier = "("+this->name+" ->timeractuator)";
    timers.push_back(this->create_wall_timer(std::chrono::milliseconds((int)timerPeriod), [this,timerWCET,timerRegisterIndex,timerIdentifier,fusionBufferIndex](){timerActuatorTimerCallback(timerWCET, timerRegisterIndex, timerIdentifier,fusionBufferIndex);}));
}

// Add subscription actuator callbacks to node
void RTNode::addSubscriptionActuator(long wcet, int bufferSize, std::string subTopic){
    registers.push_back(RTRegister());
    int registerIndex = registers.size()-1;
    std::string identifier = "("+this->name+" "+subTopic+"->actuator)";
    subscribers.push_back(this->create_subscription<rt_msgs::msg::RTHeader>(subTopic, bufferSize, [this,wcet,registerIndex,identifier](const rt_msgs::msg::RTHeader::SharedPtr msg){subscriptionActuatorCallback(wcet, registerIndex, msg, identifier);}));
}

// Sensor node timer callback
void RTNode::sensorCallback(long wcet, int pubIndex,int registerIndex, std::string identifier){

    long now = this->get_clock()->now().nanoseconds();

    rt_msgs::msg::RTHeader msg;
    rt_msgs::msg::RTEntry entry;
    if(registers[registerIndex].getLatestMessage().entries.size() == 0){
        entry = RTRegister::createEntry(now,now,std::vector<std::string> {identifier});
    }
    else{
        entry = RTRegister::createEntry(registers[registerIndex].getLatestMessage().entries[0].dataage,now,std::vector<std::string> {identifier});
    }
    msg.entries.push_back(entry);

    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();

    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(msg);
    registers[registerIndex].addMessageRegisterEntry(msg);
    registers[registerIndex].updateMessageRegisterDataAge(msg);
    registers[registerIndex].updateMessageRegisterReactionTime(msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    publishers[pubIndex]->publish(msg);
}

// Filter node subscription callback
void RTNode::filterCallback(long wcet, int pubIndex, int registerIndex, rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier){

    long now = this->get_clock()->now().nanoseconds();
    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();

    msg = RTRegister::extendHistory(msg,identifier);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(*msg);
    registers[registerIndex].addMessageRegisterEntry(*msg);
    registers[registerIndex].updateMessageRegisterDataAge(*msg);
    registers[registerIndex].updateMessageRegisterReactionTime(*msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    publishers[pubIndex]->publish(*msg);
}

// Timer fusion node subscription callback
void RTNode::timerFusionSubscriberCallback(long wcet,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier, int fusionBufferIndex){

    long now = this->get_clock()->now().nanoseconds();

    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();

    msg = RTRegister::extendHistory(msg,identifier);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(*msg);
    registers[registerIndex].addMessageRegisterEntry(*msg);
    registers[registerIndex].updateMessageRegisterDataAge(*msg);
    registers[registerIndex].updateMessageRegisterReactionTime(*msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    bool appendForward = true;
    rt_msgs::msg::RTHeader forwardMessage;
    for(auto entry: registers[registerIndex].getMessageRegister()){
        forwardMessage.entries.push_back(entry);
    }

    for(auto& entry: registers[registerIndex].getMessageRegister()){
        for(auto& fusionMessage: fusionBuffer[fusionBufferIndex]){
            for(auto& fusionEntry: fusionMessage.entries){
                if(std::equal(fusionEntry.history.begin(), fusionEntry.history.end(), entry.history.begin())){
                    fusionEntry.dataage = entry.dataage;
                    appendForward = false;
                }
            }
        }
    }
    if(appendForward){
        fusionBuffer[fusionBufferIndex].push_back(forwardMessage);
    }

}

// Timer fusion node timer callback
void RTNode::timerFusionTimerCallback(long wcet,int pubIndex,int registerIndex, std::string identifier, int fusionBufferIndex){

    long now = this->get_clock()->now().nanoseconds();
    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();

    rt_msgs::msg::RTHeader msg;

    for(auto fusionMessage: fusionBuffer[fusionBufferIndex]){
        for(auto entry: fusionMessage.entries){
            msg.entries.push_back(entry);
        }
    }
    fusionBuffer[fusionBufferIndex].clear();
    msg = RTRegister::extendHistory(msg,identifier);

    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(msg);
    registers[registerIndex].addMessageRegisterEntry(msg);
    registers[registerIndex].updateMessageRegisterDataAge(msg);
    registers[registerIndex].updateMessageRegisterReactionTime(msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    publishers[pubIndex]->publish(msg);
}

// Subscription fusion node passive subscription callback
void RTNode::subscriptionFusionSubscriberCallback(long wcet,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier, int fusionBufferIndex){

    long now = this->get_clock()->now().nanoseconds();
    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();
    msg = RTRegister::extendHistory(msg,identifier);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(*msg);
    registers[registerIndex].addMessageRegisterEntry(*msg);
    registers[registerIndex].updateMessageRegisterDataAge(*msg);
    registers[registerIndex].updateMessageRegisterReactionTime(*msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    bool appendForward = true;
    rt_msgs::msg::RTHeader forwardMessage;
    for(auto entry: registers[registerIndex].getMessageRegister()){
        forwardMessage.entries.push_back(entry);
    }

    for(auto& entry: registers[registerIndex].getMessageRegister()){
        for(auto& fusionMessage: fusionBuffer[fusionBufferIndex]){
            for(auto& fusionEntry: fusionMessage.entries){
                if(std::equal(fusionEntry.history.begin(), fusionEntry.history.end(), entry.history.begin())){
                    fusionEntry.dataage = entry.dataage;
                    appendForward = false;
                }
            }
        }
    }
    if(appendForward){
        fusionBuffer[fusionBufferIndex].push_back(forwardMessage);
    }
}

// Subscription fusion node trigger subscription callback
void RTNode::subscriptionFusionTriggerCallback(long wcet,int pubIndex,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg,std::string identifier, int fusionBufferIndex){

    long now = this->get_clock()->now().nanoseconds();
    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();


    for(auto fusionMessage: fusionBuffer[fusionBufferIndex]){
        for(auto entry: fusionMessage.entries){
            msg->entries.push_back(entry);
        }
    }
    fusionBuffer[fusionBufferIndex].clear();

    msg = RTRegister::extendHistory(msg,identifier);

    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(*msg);
    registers[registerIndex].addMessageRegisterEntry(*msg);
    registers[registerIndex].updateMessageRegisterDataAge(*msg);
    registers[registerIndex].updateMessageRegisterReactionTime(*msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    publishers[pubIndex]->publish(*msg);
}

// Timer actuator node subscription callback
void RTNode::timerActuatorSubscriptionCallback(long wcet,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier, int fusionBufferIndex){

    long now = this->get_clock()->now().nanoseconds();
    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();

    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(*msg);
    registers[registerIndex].addMessageRegisterEntry(*msg);
    registers[registerIndex].updateMessageRegisterDataAge(*msg);
    registers[registerIndex].updateMessageRegisterReactionTime(*msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    bool appendForward = true;
    rt_msgs::msg::RTHeader forwardMessage;
    for(auto entry: registers[registerIndex].getMessageRegister()){
        forwardMessage.entries.push_back(entry);
    }

    for(auto& entry: registers[registerIndex].getMessageRegister()){
        for(auto& fusionMessage: fusionBuffer[fusionBufferIndex]){
            for(auto& fusionEntry: fusionMessage.entries){
                if(std::equal(fusionEntry.history.begin(), fusionEntry.history.end(), entry.history.begin())){
                    fusionEntry.dataage = entry.dataage;
                    appendForward = false;
                }
            }
        }
    }
    if(appendForward){
        fusionBuffer[fusionBufferIndex].push_back(forwardMessage);
    }
}

// Timer actuator node timer callback
void RTNode::timerActuatorTimerCallback(long wcet,int registerIndex, std::string identifier, int fusionBufferIndex){

    long now = this->get_clock()->now().nanoseconds();
    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();

    rt_msgs::msg::RTHeader msg;

    for(auto fusionMessage: fusionBuffer[fusionBufferIndex]){
        for(auto entry: fusionMessage.entries){
            msg.entries.push_back(entry);
        }
    }
    fusionBuffer[fusionBufferIndex].clear();

    msg = RTRegister::extendHistory(msg,identifier);

    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(msg);
    registers[registerIndex].addMessageRegisterEntry(msg);
    registers[registerIndex].updateMessageRegisterDataAge(msg);
    registers[registerIndex].updateMessageRegisterReactionTime(msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    registers[registerIndex].printAnalysisRegisters();
}

// Subscription actuator node timer callback
void RTNode::subscriptionActuatorCallback(long wcet, int registerIndex, rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier){

    long now = this->get_clock()->now().nanoseconds();
    while(this->get_clock()->now().nanoseconds() < now+wcet){}

    long nowAnalysis = this->get_clock()->now().nanoseconds();

    msg = RTRegister::extendHistory(msg,identifier);
    
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].setLatestMessage(*msg);
    registers[registerIndex].addMessageRegisterEntry(*msg);
    registers[registerIndex].updateMessageRegisterDataAge(*msg);
    registers[registerIndex].updateMessageRegisterReactionTime(*msg);
    registers[registerIndex].updateAnalysisRegisterDataAge(nowAnalysis);
    registers[registerIndex].updateAnalysisRegisterReactionTime(nowAnalysis);

    registers[registerIndex].printAnalysisRegisters();
}
