# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.241.1/containers/ubuntu/.devcontainer/base.Dockerfile

# [Choice] Ubuntu version (use ubuntu-22.04 or ubuntu-18.04 on local arm64/Apple Silicon): ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="focal"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# [Optional] Uncomment this section to install additional OS packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
     && apt-get -y install --no-install-recommends \
     software-properties-common curl gnupg2 lsb-release \
     apt-transport-https gcc g++
RUN add-apt-repository universe

RUN sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key  -o /usr/share/keyrings/ros-archive-keyring.gpg

RUN echo "deb [arch=amd64 signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu focal main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

RUN apt-get update \
     && export DEBIAN_FRONTEND=noninteractive \
     && apt-get -y install --no-install-recommends \
     ros-foxy-desktop ros-foxy-rmw-cyclonedds-cpp \
     python3-colcon-common-extensions

#RUN mkdir /home/vscode
#RUN echo 'source /opt/ros/foxy/setup.bash' >> /home/vscode/.bashrc
#ENV source /opt/ros/foxy/setup.bash
ENV RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
