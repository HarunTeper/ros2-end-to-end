#include "rclcpp/rclcpp.hpp"
#include <string>
#include <vector>
#include <map>

#include "rt_nodes/rt_register.hpp"

class RTNode : public rclcpp::Node
{
    public:
        RTNode(std::string name);
        ~RTNode();

        void addSensor(double period, long wcet, int bufferSize, std::string pubTopic);
        void addFilter(long wcet, int bufferSize, std::string subTopic, std::string pubTopic);
        void addTimerFusion(std::vector<long> wcets, std::vector<int> bufferSizes, std::vector<std::string> subTopics, double period, long wcet, int bufferSize, std::string pubTopic);
        void addSubscriptionFusion(std::vector<long> wcets, std::vector<int> bufferSizes, std::vector<std::string> subTopics, std::string pubTopic);
        void addTimerActuator(long subWCET, int subBufferSize, std::string subTopic, double timerPeriod, long timerWCET, int timerBufferSize);
        void addSubscriptionActuator(long wcet, int bufferSize, std::string subTopic);

        // void addSensorTimerPub(int period, int wcet, int bufferSize, std::string topicName);
        // void addSub(int wcet, int bufferSize, std::string topicName);
        // void addFusionTimerPub(int period, int wcet,std::vector<int> wcets, int bufferSize, std::vector<std::string> subTopicNames, std::string pubTopicName);
        // void addSubPub(int wcet, int bufferSize, std::string subTopicName, std::string pubTopicName);

    // protected:

    // private:
        void sensorCallback(long wcet, int pubIndex, int registerIndex, std::string identifier);

        void filterCallback(long wcet, int pubIndex, int registerIndex, rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier);

        void timerFusionSubscriberCallback(long wcet,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier, int fusionBufferIndex);
        void timerFusionTimerCallback(long wcet,int pubIndex,int registerIndex,std::string identifier, int fusionBufferIndex);

        void subscriptionFusionSubscriberCallback(long wcet,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier, int fusionBufferIndex);
        void subscriptionFusionTriggerCallback(long wcet,int pubIndex,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg,std::string identifier, int fusionBufferIndex);
        
        void timerActuatorSubscriptionCallback(long wcet,int registerIndex,rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier, int fusionBufferIndex);
        void timerActuatorTimerCallback(long wcet,int registerIndex,std::string identifier, int fusionBufferIndex);

        void subscriptionActuatorCallback(long wcet, int registerIndex, rt_msgs::msg::RTHeader::SharedPtr msg, std::string identifier);


        // void SensorTimerCallback(int wcet, std::string topicName, int idIndex, int pubIndex);
        // void SubCallback(int wcet, const rt_msgs::msg::RTHeader::SharedPtr msg);
        // void FusionTimerCallback(int wcet, std::vector<std::string> subTopicNames, std::string pubTopicName,std::vector<int> subIndices, int pubIndex);
        // void FusionSubCallback(int wcet, std::string topicName, const rt_msgs::msg::RTHeader::SharedPtr msg, int index);
        // void SubPubCallback(int wcet, std::string subTopicName, std::string pubTopicName, int pubIndex, const rt_msgs::msg::RTHeader::SharedPtr msg);

        std::string name;
        std::vector<rclcpp::Publisher<rt_msgs::msg::RTHeader>::SharedPtr> publishers;
        std::vector<rclcpp::Subscription<rt_msgs::msg::RTHeader>::SharedPtr> subscribers;
        std::vector<std::vector<rt_msgs::msg::RTHeader>> fusionBuffer;
        std::vector<rclcpp::TimerBase::SharedPtr> timers;
        std::vector<RTRegister> registers;

};