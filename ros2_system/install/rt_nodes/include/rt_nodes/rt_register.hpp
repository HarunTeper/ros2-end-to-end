#include "rclcpp/rclcpp.hpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "rt_msgs/msg/rt_header.hpp"
#include "rt_msgs/msg/rt_entry.hpp"


template <typename T>
std::ostream& operator<<(std::ostream& output, std::vector<T> const& values)
{
    for (auto value : values)
    {
        output << value;
    }
    return output;
}

class RTRegister
{
    public:
        RTRegister(){};
        ~RTRegister(){};

        static rt_msgs::msg::RTEntry createEntry(long reactionTime, long dataAge, std::vector<std::string> history){
            rt_msgs::msg::RTEntry msg;
            msg.reactiontime = reactionTime;
            msg.dataage = dataAge;
            msg.history = history;
            return msg;
        }

        static rt_msgs::msg::RTHeader::SharedPtr extendHistory(rt_msgs::msg::RTHeader::SharedPtr msg, std::string historyElement){
            for(int i = 0;i<msg->entries.size();i++){
                msg->entries[i].history.push_back(historyElement);
            }
            return msg;
        }

        static rt_msgs::msg::RTHeader extendHistory(rt_msgs::msg::RTHeader &msg, std::string &historyElement){
            for(int i = 0;i<msg.entries.size();i++){
                msg.entries[i].history.push_back(historyElement);
            }
            return msg;
        }

        void addMessageRegisterEntry(rt_msgs::msg::RTHeader &msg){
            for(auto entry : msg.entries){
                if(!std::any_of(messageRegister.begin(),messageRegister.end(), [&entry](auto msgRegisterEntry){return msgRegisterEntry.history == entry.history;})){
                    messageRegister.push_back(entry);
                }
            }
        };

        void updateMessageRegisterReactionTime(rt_msgs::msg::RTHeader &msg){
            for(auto entry : msg.entries){
                auto result = std::find_if(messageRegister.begin(),messageRegister.end(), [&entry](auto msgRegisterEntry){return msgRegisterEntry.history == entry.history;});
                result->reactiontime = entry.reactiontime;
            }
        };

        void updateMessageRegisterDataAge(rt_msgs::msg::RTHeader &msg){
            for(auto entry : msg.entries){
                auto result = std::find_if(messageRegister.begin(),messageRegister.end(), [&entry](auto msgRegisterEntry){return msgRegisterEntry.history == entry.history;});
                result->dataage = entry.dataage;
            }
        };

        void updateAnalysisRegisterReactionTime(long now){
            for(auto entry : messageRegister){
                auto result = std::find_if(analysisRegister.begin(),analysisRegister.end(), [&entry](auto analysisRegisterEntry){return analysisRegisterEntry.history == entry.history;});
                if(result == analysisRegister.end()){
                    analysisRegister.push_back(entry);
                    analysisRegister.back().reactiontime = now-analysisRegister.back().reactiontime;
                    analysisRegister.back().dataage = now-analysisRegister.back().dataage;
                }
                else{
                    result->reactiontime = std::max(result->reactiontime,now-entry.reactiontime);
                }
            }
        };

        void updateAnalysisRegisterDataAge(long now){
            for(auto entry : messageRegister){
                auto result = std::find_if(analysisRegister.begin(),analysisRegister.end(), [&entry](auto analysisRegisterEntry){return analysisRegisterEntry.history == entry.history;});
                if(result == analysisRegister.end()){
                    analysisRegister.push_back(entry);
                    analysisRegister.back().reactiontime = now-analysisRegister.back().reactiontime;
                    analysisRegister.back().dataage = now-analysisRegister.back().dataage;
                }
                else{
                    result->dataage = std::max(result->dataage,now-entry.dataage);
                }
            }
        };

        void equalizeTimingValues(){
            for(int i = 0;i<messageRegister.size();i++){
                messageRegister[i].reactiontime = messageRegister[i].dataage;
            }
        };

        void setLatestMessage(rt_msgs::msg::RTHeader &msg){
            this->latestMessage = msg;
        }

        rt_msgs::msg::RTHeader getLatestMessage(){
            return this->latestMessage;
        }

        std::vector<rt_msgs::msg::RTEntry> getMessageRegister(){
            return this->messageRegister;
        }

        void printMessageRegisters(){
            std::cout << "Messages" << std::endl;
            for(auto entry : messageRegister){
                std::cout << entry.dataage << " " << entry.reactiontime << " " << entry.history << std::endl;
            }
        }

        void printAnalysisRegisters(){
            std::cout << "----------" << std::endl;
            std::cout << std::endl;
            for(auto entry : analysisRegister){
                std::cout << "Chain: " << entry.history << std::endl;
                std::cout << "Maximum reaction time: " << entry.reactiontime*1e-9 << std::endl;
                std::cout << "Maximum data age: " << entry.dataage*1e-9 << std::endl;
            std::cout << std::endl;
            }
        }
        
        void printAll(){
            printMessageRegisters();
            printAnalysisRegisters();
        }

    // private:
        std::string name;
        std::vector<rt_msgs::msg::RTEntry> messageRegister;
        std::vector<rt_msgs::msg::RTEntry> analysisRegister;
        rt_msgs::msg::RTHeader latestMessage;

};