#include "rt_nodes/rt_node.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    std::shared_ptr<RTNode> ptr = std::make_shared<RTNode>("node1");

    int time = 0;

    if(argc == 3){
        if(!strcmp(argv[1], "navigation_system")){
            int cameraNum = std::stoi(argv[2]);
            std::vector<long> wcets;
            std::vector<int> buffersizes;
            std::vector<std::string> topics;
            for(int i = 0;i<cameraNum;i++){
                std::string name = "CAMERA"+std::to_string(i);
                ptr->addSensor(100,5e6,10,name);
                wcets.push_back((long)5e6);
                buffersizes.push_back(10);
                topics.push_back(name);
            }

            ptr->addSubscriptionFusion(wcets, buffersizes, topics, "CAMERAFUSION");
            ptr->addFilter((long)10e6,10,"CAMERAFUSION","PERCEPTION");
            ptr->addFilter((long)10e6,10,"PERCEPTION","PLANNING");
            ptr->addFilter((long)10e6,10,"PLANNING","CONTROL");
            ptr->addSubscriptionActuator((long)10e6,10,"CONTROL");

            time = 10;
        }
        else{
            std::cout << "Wrong system name" << std::endl;
            return 1;
        }
    }
    else if (argc == 4){
        if(!strcmp(argv[1], "navigation_system")){
            int cameraNum = std::stoi(argv[2]);
            std::vector<long> wcets;
            std::vector<int> buffersizes;
            std::vector<std::string> topics;
            for(int i = 0;i<cameraNum;i++){
                std::string name = "CAMERA"+std::to_string(i);
                ptr->addSensor(100,5e6,10,name);
                wcets.push_back((long)5e6);
                buffersizes.push_back(10);
                topics.push_back(name);
            }

            ptr->addSubscriptionFusion(wcets, buffersizes, topics, "CAMERAFUSION");
            ptr->addFilter((long)10e6,10,"CAMERAFUSION","PERCEPTION");
            ptr->addFilter((long)10e6,10,"PERCEPTION","PLANNING");
            ptr->addFilter((long)10e6,10,"PLANNING","CONTROL");
            ptr->addSubscriptionActuator((long)10e6,10,"CONTROL");

            time = std::stoi(argv[3]);
        }
        else if(!strcmp(argv[1], "case_study")){
            if(!strcmp(argv[2], "under")){
                if(!strcmp(argv[3], "SS")){
                    ptr->addSensor(360,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(360,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                }
                else if(!strcmp(argv[3], "ST")){
                    ptr->addSensor(420,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(420,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 840, (long)30e6, 10);
                }
                else if(!strcmp(argv[3], "TS")){
                    ptr->addSensor(420,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(420,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 840, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                }
                else if(!strcmp(argv[3], "TT")){
                    ptr->addSensor(480,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(480,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 960, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 960, (long)30e6, 10);
                }
                else{
                    std::cout << "Wrong fusion and actuator names" << std::endl;
                    return 1;
                }
            }
            else if(!strcmp(argv[2], "over")){
                if(!strcmp(argv[3], "SS")){
                    ptr->addSensor(90,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(90,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                }
                else if(!strcmp(argv[3], "ST")){
                    ptr->addSensor(105,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(105,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 52.5, (long)30e6, 10);
                }
                else if(!strcmp(argv[3], "TS")){
                    ptr->addSensor(105,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(105,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 52.5, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                    
                }
                else if(!strcmp(argv[3], "TT")){
                    ptr->addSensor(120,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(120,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 60, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 60, (long)30e6, 10);
                }
                else{
                    std::cout << "Wrong fusion and actuator names" << std::endl;
                    return 1;
                }
            }
            else{
                std::cout << "Wrong utilization name" << std::endl;
                return 1;
            }
            time = 10;
        }
        else{
            std::cout << "Wrong system name" << std::endl;
            return 1;
        }
    }
    else if (argc == 5){
        if(!strcmp(argv[1], "case_study")){
            if(!strcmp(argv[2], "under")){
                if(!strcmp(argv[3], "SS")){
                    ptr->addSensor(360,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(360,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                }
                else if(!strcmp(argv[3], "ST")){
                    ptr->addSensor(420,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(420,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 840, (long)30e6, 10);
                }
                else if(!strcmp(argv[3], "TS")){
                    ptr->addSensor(420,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(420,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 840, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                }
                else if(!strcmp(argv[3], "TT")){
                    ptr->addSensor(480,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(480,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 960, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 960, (long)30e6, 10);
                }
                else{
                    std::cout << "Wrong fusion and actuator names" << std::endl;
                    return 1;
                }
            }
            else if(!strcmp(argv[2], "over")){
                if(!strcmp(argv[3], "SS")){
                    ptr->addSensor(90,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(90,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                }
                else if(!strcmp(argv[3], "ST")){
                    ptr->addSensor(105,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(105,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addSubscriptionFusion(std::vector<long> {(long)30e6,(long)30e6}, std::vector<int> {10,10}, std::vector<std::string> {"filter1","filter2"}, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 52.5, (long)30e6, 10);
                }
                else if(!strcmp(argv[3], "TS")){
                    ptr->addSensor(105,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(105,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 52.5, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addSubscriptionActuator((long)30e6,10,"filter3");
                    
                }
                else if(!strcmp(argv[3], "TT")){
                    ptr->addSensor(120,(long)10e6,10,"sensor1");
                    ptr->addFilter((long)10e6,10,"sensor1","filter1");
                    ptr->addSensor(120,(long)20e6,10,"sensor2");
                    ptr->addFilter((long)20e6,10,"sensor2","filter2");
                    ptr->addTimerFusion(std::vector<long>{(long)30e6,(long)30e6}, std::vector<int>{10,10}, std::vector<std::string>{"filter1","filter2"}, 60, (long)30e6, 10, "fusion1");
                    ptr->addFilter((long)30e6,10,"fusion1","filter3");
                    ptr->addTimerActuator((long)30e6, 10, "filter3", 60, (long)30e6, 10);
                }
                else{
                    std::cout << "Wrong fusion and actuator names" << std::endl;
                    return 1;
                }
            }
            else{
                std::cout << "Wrong utilization name" << std::endl;
                return 1;
            }
        }
        else{
            std::cout << "Wrong system name" << std::endl;
            return 1;
        }
        time = std::stoi(argv[4]);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    while(true)
    {
        rclcpp::spin_some(ptr);
        end = std::chrono::high_resolution_clock::now();
        auto duration = end - start;

        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
        if(seconds > std::chrono::seconds(time)){
            break;
        }
    }
    rclcpp::shutdown();
    return 0;
}