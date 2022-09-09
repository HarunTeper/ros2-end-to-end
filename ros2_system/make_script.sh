source /opt/ros/foxy/setup.bash
rm -rf ~/ros2-end-to-end/ros2_system/build
rm -rf ~/ros2-end-to-end/ros2_system/log
rm -rf ~/ros2-end-to-end/ros2_system/install
colcon build --symlink-install
source install/setup.bash
