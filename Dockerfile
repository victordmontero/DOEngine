FROM debian

RUN apt update -y
# RUN apt install -y gcc g++ gdb git cmake libxml2-dev zlib1g-dev liblzma-dev libicu-dev libncurses5-dev \
# 	mingw-w64 wget libdbus-1-3 libxcb-cursor0 libxcb-glx0 libx11-xcb1 libxcb-icccm4 libxcb-keysyms1 libxcb-randr0 libxcb-shape0 \
# 	libxcb-sync-dev libxcb-xfixes0 libxcb-xinerama0 libxcb-xkb-dev libxkbcommon-x11-0 libgl-dev libgl1-mesa-dev adduser

RUN apt install -y gcc g++ gdb git cmake mingw-w64 libegl1-mesa-dev libibus-1.0-5 libibus-1.0-dev libice-dev libsm-dev libsndio-dev libwayland-bin libwayland-dev libxi-dev libxinerama-dev libxkbcommon-dev libxrandr-dev libxss-dev libxt-dev libxv-dev x11proto-randr-dev x11proto-scrnsaver-dev x11proto-video-dev x11proto-xinerama-dev

RUN mkdir -p /home/doengine

WORKDIR /home/doengine

CMD ["/bin/bash"]

VOLUME /home/doengine
