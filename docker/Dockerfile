ARG OVERLAY_WS=/opt/ros/overlay_ws
ARG BASE_REPOSITORY=dustynv/ros
ARG BASE_TAG=galactic-ros-base-l4t-r32.6.1
ARG BASE_IMAGE=$BASE_REPOSITORY:$BASE_TAG

FROM $BASE_IMAGE AS base

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
