ARG OVERLAY_WS=/opt/ros/overlay_ws
ARG L4T_RELEASE=32
ARG L4T_REVISION_MAJOR=6
ARG L4T_REVISION_MINOR=1
ARG L4T_VERSION=$L4T_RELEASE.$L4T_REVISION_MAJOR.$L4T_REVISION_MINOR

FROM dustynv/ros:galactic-ros-base-l4t-r$L4T_VERSION AS base

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
         geographiclib-tools \
         libfmt-dev \
         libboost-dev \
    && rm -rf /var/lib/apt/list/*


FROM base AS builder

ARG OVERLAY_WS
WORKDIR $OVERLAY_WS/src

COPY ./docker/overlay.repos ../
RUN vcs import ./ < ../overlay.repos

# build overlay source
WORKDIR $OVERLAY_WS

RUN . /opt/ros/$ROS_DISTRO/install/setup.sh && \
    colcon build \
        --cmake-args -DCMAKE_BUILD_TYPE=Release --packages-up-to boot_shutdown_interface

ENV OVERLAY_WS=${OVERLAY_WS}

# source entrypoint setup
RUN sed --in-place --expression \
      '$isource "$OVERLAY_WS/install/setup.bash"' \
      /ros_entrypoint.sh

ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]
WORKDIR /
