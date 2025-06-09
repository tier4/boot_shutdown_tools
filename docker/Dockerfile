ARG OVERLAY_WS=/opt/ros/overlay_ws
ARG BASE_REPOSITORY=dustynv/ros
ARG BASE_TAG=galactic-ros-base-l4t-r32.6.1
ARG BASE_IMAGE=$BASE_REPOSITORY:$BASE_TAG

FROM $BASE_IMAGE AS base

RUN rm -f /etc/apt/sources.list.d/ros2.list /etc/apt/sources.list.d/ros2.list.save \
    && rm -f /usr/share/keyrings/ros-archive-keyring.gpg \
    && apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 16FAAD7AF99A65E2

RUN apt-get update \
  && apt-get install -y ca-certificates curl
# hadolint ignore=SC1091
RUN export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F\" '{print $4}') ;\
  curl -L -s -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo "$VERSION_CODENAME")_all.deb" \
  && apt-get update \
  && apt-get install -y /tmp/ros2-apt-source.deb \
  && rm -f /tmp/ros2-apt-source.deb

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
         geographiclib-tools \
         libfmt-dev \
         libboost-dev \
    && rm -rf /var/lib/apt/list/*

ARG OVERLAY_WS
WORKDIR $OVERLAY_WS/src

COPY ./docker/overlay.repos ../
RUN vcs import ./ < ../overlay.repos

# build overlay source
WORKDIR $OVERLAY_WS

RUN . /opt/ros/$ROS_DISTRO/install/setup.sh && \
    colcon build \
        --cmake-args -DCMAKE_BUILD_TYPE=Release --merge-install --packages-up-to boot_shutdown_interface

ENV OVERLAY_WS=${OVERLAY_WS}

# source entrypoint setup
RUN sed --in-place --expression \
      '$isource "$OVERLAY_WS/install/setup.bash"' \
      /ros_entrypoint.sh

ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]
WORKDIR /
