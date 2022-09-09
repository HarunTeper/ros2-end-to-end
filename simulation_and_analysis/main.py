"""Main class"""

import sys
from analysis import Analysis
from node import Node

def add_system_to_node(node, experiment, arg1, arg2):
    """Adds node classes to node"""

    if experiment == "navigation_system":
        camera_number = arg1

        wcets = []
        buffer_sizes = []
        topics = []
        for i in range(camera_number):
            name = "CAMERA"+str(i)
            node.add_sensor(0, 0.1, 0.005, 10, name)
            wcets.append(0.005)
            buffer_sizes.append(10)
            topics.append(name)
        node.add_subscription_fusion(wcets, buffer_sizes, topics, "CAMERAFUSION")
        node.add_filter(0.01, 10, "CAMERAFUSION", "PERCEPTION")
        node.add_filter(0.01, 10, "PERCEPTION", "PLANNING")
        node.add_filter(0.01, 10, "PLANNING", "CONTROL")
        node.add_subscription_actuator(0.01, 10, "CONTROL")
    elif experiment == "case_study":
        if arg1 == "over":
            if arg2 == "SS":
                node.add_sensor(0,90,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,90,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_subscription_fusion([30.0,30.0],[10,10],["process1","process2"],"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_subscription_actuator(30.0,10,"filter3")
            elif arg2 == "ST":
                node.add_sensor(0,105,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,105,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_subscription_fusion([30.0,30.0],[10,10,10],["process1","process2"],"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_timer_actuator(30.0,10,"filter3",0,52.5,30.0,10)
            elif arg2 == "TS":
                node.add_sensor(0,105,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,105,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_timer_fusion([30.0,30.0],[10,10],["process1","process2"],0,52.5,30.0,10,"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_subscription_actuator(30.0,10,"filter3")
            elif arg2 == "TT":
                node.add_sensor(0,120.0,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,120.0,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_timer_fusion([30.0,30.0],[10,10],["process1","process2"],0,60.0,30.0,10,"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_timer_actuator(30.0,10,"filter3",0,60.0,30.0,10)
        if arg1 == "under":
            if arg2 == "SS":
                node.add_sensor(0,360,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,360,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_subscription_fusion([30.0,30.0],[10,10,10],["process1","process2"],"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_subscription_actuator(30.0,10,"filter3")
            elif arg2 == "ST":
                node.add_sensor(0,420,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,420,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_subscription_fusion([30.0,30.0],[10,10,10],["process1","process2"],"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_timer_actuator(30.0,10,"filter3",0,840,30.0,10)
            elif arg2 == "TS":
                node.add_sensor(0,420,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,420,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_timer_fusion([30.0,30.0],[10,10],["process1","process2"],0,840,30.0,10,"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_subscription_actuator(30.0,10,"filter3")
            elif arg2 == "TT":
                node.add_sensor(0,480,10.0,10,"sensor1")
                node.add_filter(10.0,10,"sensor1","process1")
                node.add_sensor(0,480,20.0,10,"sensor2")
                node.add_filter(20.0,10,"sensor2","process2")
                node.add_timer_fusion([30.0,30.0],[10,10],["process1","process2"],0,960,30.0,10,"fusion1")
                node.add_filter(30.0,10,"fusion1","filter3")
                node.add_timer_actuator(30.0,10,"filter3",0,960,30.0,10)

def run_analysis(selector, experiment, arg1, arg2):
    """Creates and runs analysis"""

    # Create analyis
    analysis1 = Analysis()

    # Add node to the system
    node1 = Node("node1")
    add_system_to_node(node1, experiment, arg1, arg2)

    # Add node to the analysis executor
    analysis1.add_node_to_executor(node1)

    if selector == "simulation" or selector == "both":
        print("Simulation")
        # Run the system
        for _ in range(1000):
            analysis1.simulate_next_processing_window()
        # Print simulation results
        analysis1.print_analysis()

    if selector == "analysis" or selector == "both":
        print("Analysis")
        #Calculate upper bounds
        analysis1.calculate_upper_bounds()

def main():
    """Main"""
    if len(sys.argv) == 4:
        selector = sys.argv[1]
        if not any(selector == elem for elem in ["analysis","simulation","both"]):
            print("Simulation analysis selection incorrect")
            return
        experiment = sys.argv[2]
        if not any(experiment == elem for elem in ["navigation_system"]):
            print("Experiment name incorrect")
            return
        number = int(sys.argv[3])
        run_analysis(selector, experiment, number, 0)
    elif len(sys.argv) == 5:
        selector = sys.argv[1]
        if not any(selector == elem for elem in ["analysis","simulation","both"]):
            print("Simulation analysis selection incorrect")
            return
        experiment = sys.argv[2]
        if not any(experiment == elem for elem in ["case_study"]):
            print("Experiment selection incorrect")
            return
        utilization = sys.argv[3]
        if not any(utilization == elem for elem in ["under","over"]):
            print("Utilization selection incorrect")
            return
        system_type = sys.argv[4]
        if not any(system_type == elem for elem in ["SS","ST","TS","TT"]):
            print("System type selection incorrect")
            return
        run_analysis(selector, experiment, utilization, system_type)
    else:
        print("Wrong arguments entered")




if __name__ == "__main__":
    main()
