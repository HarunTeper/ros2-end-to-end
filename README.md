
# End-To-End Timing Analysis

The repository is used to reproduce the evaluation from

*End-To-End Timing Analysis in ROS2*

for RTSS 2022.

To replicate the experiment in the paper, please use the VM and run the experiments.

This document is organized as follows:
- [End-To-End Timing Analysis](#end-to-end-timing-analysis)
  - [How to use VM](#how-to-use-vm)
  - [Experiment Overview](#experiment-overview)
    - [How to run the experiments](#how-to-run-the-experiments)
    - [ROS2 system execution](#ros2-system-execution)
      - [Case Study](#case-study)
      - [Evaluation](#evaluation)
    - [ROS2 system simulation and upper bound analysis](#ros2-system-simulation-and-upper-bound-analysis)
      - [Case Study](#case-study-1)
      - [Evaluation](#evaluation-1)
    - [File Structure](#file-structure)
    - [Overview of the corresponding functions and algorithms](#overview-of-the-corresponding-functions-and-algorithms)
  - [Environment Setup](#environment-setup)
    - [Requirements](#requirements)
    - [Deployment](#deployment)
    - [System and run time details](#system-and-run-time-details)
  - [Miscellaneous](#miscellaneous)
    - [Authors](#authors)
    - [Acknowledgments](#acknowledgments)

## How to use VM

- Please download the [zip file](https://tu-dortmund.sciebo.de/s/Po3B0vSe3UGjEEV), which contains the virtual disk and the machine description. The credential is: ros2end2end/rtss2022
- The source code is deployed on the desktop already. Some common software are installed accordingly, e.g., vscode, git.
- Please follow the above description to test out the provided analyses.
- Please note that the scripts are for reproducing the results on the paper.

If you want to install everything manually, please refer the section **Environment Setup**.

## Experiment Overview
    
The experiments are split into three parts:

1. ROS2 system execution (/ros2_system)
2. ROS2 system simulation (/simulation_and_analysis)
3. Upper bound analysis (/simulation_and_analysis)

The **ROS2 system execution** reproduces the **observed** results for the case-study and evaluation and can needs to be run in the ros2_system folder.
The **ROS2 system simulation** reproduces the **lower bound** results for the case-study and evaluation and can needs to be run in the simulation_and_analysis folder.
The **Upper bound analysis** reproduces the **upper bound** results for the case-study and evaluation and can needs to be run in the simulation_and_analysis folder.

The results of the experiments will be displayed in the terminal that executes the scripts.

### How to run the experiments

We explain how to run each experiment by itself to reproduce the results of the evaluation. Note that we first give full instructions on how to reproduce the results, after which we provide more in-depth explanations on how to configure the experiments.

We refer to the **Case-Study** in Section VIII and the **Evaluation** in Section IX in the paper.

### ROS2 system execution

This section includes how to reproduce the results of the observed values:

Start a terminal and move into the ros2_system folder:
```
cd ~/ros2-end-to-end/ros2_system
```
Execute the make_script:
```
./make_script.sh
```
Source the packages:
```
source install/setup.bash
```
#### Case Study

To replicate the results from the case-study, you need to run eight different systems for 10 seconds.

There are eight different configurations, using under-utilized **(under)** or over-utilized systems **(over)** and four different component combinations **XY**, where **X** represents either a subscription fusion **(S)** or timer fusion **(T)**, and Y represents either a susbcription actuator **(S)** or timer actuator **(T)**.

While the system is running, the terminal displays the maximum reaction time and maximum data age for two different cause-effect-chains. You can identify the chain using the index of the first sensor of the chain.
Please note that you need to compare your results to the evaluation after every command has finished, as the next command may overwrite the outputs in the terminal.
In addition, the observed values may fluctuate depending on your system configuration.

After following the previous instructions to build and source the packages, run the following commands:
```
ros2 run rt_nodes run_system case_study over SS
ros2 run rt_nodes run_system case_study over ST
ros2 run rt_nodes run_system case_study over TS
ros2 run rt_nodes run_system case_study over TT
ros2 run rt_nodes run_system case_study under SS
ros2 run rt_nodes run_system case_study under ST
ros2 run rt_nodes run_system case_study under TS
ros2 run rt_nodes run_system case_study under TT
```
In addition, you can set the execution duration in seconds using an additional argument:
```
ros2 run rt_nodes run_system case_study over SS 30
```
#### Evaluation
To replicate the results from the case-study, you need to run the navigation system and set the number of cameras. We evaluated a system with one to ten cameras. Please note that we only analyze the first chain in the evaluation, which starts with **CAMERA0**. 

Please use the following commands to run our experiments:
```
ros2 run rt_nodes run_system navigation_system 1
ros2 run rt_nodes run_system navigation_system 2
ros2 run rt_nodes run_system navigation_system 3
ros2 run rt_nodes run_system navigation_system 4
ros2 run rt_nodes run_system navigation_system 5
ros2 run rt_nodes run_system navigation_system 6
ros2 run rt_nodes run_system navigation_system 7
ros2 run rt_nodes run_system navigation_system 8
ros2 run rt_nodes run_system navigation_system 9
ros2 run rt_nodes run_system navigation_system 10
```
You can set the execution duration in seconds using an additional argument:
```
ros2 run rt_nodes run_system navigation_system 1 30
```
### ROS2 system simulation and upper bound analysis

This section includes how to reproduce the results of the lower bound and upper bound:

Start a terminal and move into the simulation_and_analysis folder:
```
cd ~/ros2-end-to-end/simulation_and_analysis
```
#### Case Study

To replicate the results from the case-study, you need to run eight different systems. The scripts only need a few seconds to complete in our cases.

There are eight different configurations, using under-utilized **(under)** or over-utilized systems **(over)** and four different component combinations **XY**, where **X** represents either a subscription fusion **(S)** or timer fusion **(T)**, and Y represents either a susbcription actuator **(S)** or timer actuator **(T)**.

After the script has finished, it displays the maximum reaction time and maximum of all chains, which are stored in the last callback of the chain.

Please note that you need to compare your results to the evaluation after every command has finished, as the next command may overwrite the outputs in the terminal.

After following the previous instructions, run the following commands:
```
python3 main.py both case_study over SS
python3 main.py both case_study over ST
python3 main.py both case_study over TS
python3 main.py both case_study over TT
python3 main.py both case_study under SS
python3 main.py both case_study under ST
python3 main.py both case_study under TS
python3 main.py both case_study under TT
```
If you want to only run the simulation or upper bound analysis, replace the argument **both** with either **simulation** or **analysis**, respectively. For example, run these commands separately:
```
python3 main.py simulation case_study over SS
python3 main.py analysis case_study over SS
```

#### Evaluation
To replicate the results from the case-study, you need to run the navigation system and set the number of cameras. We evaluated a system with one to ten cameras. Please note that we only analyze the first chain in the evaluation, which starts with **CAMERA0**. Please use the following commands to run our experiments:
```
python3 main.py both navigation_system 1
python3 main.py both navigation_system 2
python3 main.py both navigation_system 3
python3 main.py both navigation_system 4
python3 main.py both navigation_system 5
python3 main.py both navigation_system 6
python3 main.py both navigation_system 7
python3 main.py both navigation_system 8
python3 main.py both navigation_system 9
python3 main.py both navigation_system 10
```
If you want to only run the simulation or upper bound analysis, replace the argument **both** with either **simulation** or **analysis**, respectively. For example, run these commands separately:
```
python3 main.py simulation navigation_system 2
python3 main.py analysis navigation_system 2
```

### File Structure

    .
    ├── ros2_system				# System execution in ROS2-Foxy
    │   └── src				# Package src folder
    │       ├── rt_msgs			# Custom real-time message package
    │       │   ├── msg			# Single ECU chains + results
    │       │   │   ├── RTEntry.msg		# Entries for end-to-end measurements
    │       │   │   └── RTHeader.msg		# Header for end-to-end measurements
    │       │   ├── CMakeLists.txt		# Build instructions
    │       │   └── package.xml		# Package details
    │       └── rt_nodes			# Output for the runtime evaluation
    │           ├── include			# Include files
    │           │   └── rt_nodes		#
    │           │       ├── rt_node.hpp	# Real-time node classes
    │           │       └── rt_register.hpp	# Real-time end-to-end registers
    │           ├── src			# Source files
    │           │   ├── main.cpp		# Main function
    │           │   └── rt_node.cpp		# Real-time node classes
    │           ├── CMakeLists.txt		# Build instructions
    │           └── package.xml		# Package details
    ├── simulation_and_analysis		# Python simulation and upper bound analysis
    │   ├── analysis.py			# Analysis and simulation main script
    │   ├── entry.py				# Entries for end/to/end measurements
    │   ├── executor.py			# ROS2 executor model
    │   ├── message.py				# RTHeader message model
    │   ├── node.py				# ROS2 node model
    │   ├── subscription.py			# ROS2 subscription model
    │   └── timer.py				# ROS2 timer model
    └── README.md

### Overview of the corresponding functions and algorithms

The following tables describe the mapping between content of our paper and the source code in this repository.

**Section 6** (Cause-Effect Chain Upper Bound Analysis):
| Paper theorem             | Source code | methods                  |
| ------------------------- | ----------- | ------------------------ |
| (1) Maximum Reaction Time | analysis.py | calculate_upper_bounds() |

**Section 7.A** (Executor Simulation):
| Paper algorithm         | Source code | methods                           |
| ----------------------- | ----------- | --------------------------------- |
| (1) Executor Simulation | analysis.py | simulate_next_processing_window() |

**Section 7.B** (Online timing measurement):
| Paper algorithm            | Source code | methods                         |
| -------------------------- | ----------- | ------------------------------- |
| (2) Message Creation       | rt_node.cpp | RTNode::*Callback()             |
| (3) Subscription Execution | rt_node.cpp | RTNode::*SubscriptionCallback() |
| (4) Timer Execution        | rt_node.cpp | RTNode::*TimerCallback()        |

## Environment Setup
### Requirements

The experiments are split into three parts:

1. ROS2 system execution
2. ROS2 system simulation
3. Upper bound analysis

The **ROS2 system execution** requires a system running Ubuntu 20.04, while the **ROS2 system simulation** and **Upper bound analysis** can be run on any system running Python 3. 
Please note that we are running Python 3.8.10, which is the current version that is provided with Ubuntu 20.04.

For the **ROS2 system execution**, ROS2-Foxy is required.

The installation steps can be found here:
```
https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html
```
Add ROS2 to your bashrc file:
```
echo 'source /opt/ros/foxy/setup.bash' >> ~/.bashrc
```
Install Eclipse Cyclone DDS:
```
sudo apt install ros-foxy-rmw-cyclonedds-cpp
```
Install colcon:
```
sudo apt install python3-colcon-common-extensions
```
To switch to Cyclone DDS, execute the following command after launching every terminal:
```
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
```
Or add the line to the .bashrc file in your home folder:
```
echo 'export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp' >> ~/.bashrc
```
Note that you need to start a new terminal to run the commands in the bashrc file.

### Deployment

The following steps explain how to deploy the experiments on the machine.

First, clone the git repository or download the [zip file](https://github.com/HarunTeper/ros2-end-to-end):
```
git clone https://github.com/HarunTeper/ros2-end-to-end
```
Move into the ros2_system folder, change the permissions of the script to be executable, and execute make_script.sh natively:
```
cd ros2_system
chmod 777 make_script.sh
./make_script.sh
```

### System and run time details

As a reference, we utilize a machine running Ubuntu 20.04, with an AMD Ryzen 5900 12-Core Processor (12 Cores, 24 Threads) with 3,7GHz and 32GB RAM.

For the virtual machine, we enabled 4 cores and 4096 MB of RAM.

## Miscellaneous

### Authors

* Harun Teper
* Mario Günzel
* Niklas Ueter
* Georg von der Brüggen
* Jian-Jia Chen

### Acknowledgments

This work has been supported by the Federal Ministry of Education
and Research (BMBF) in the course of the project 6GEM under
the funding reference 16KISK038.

