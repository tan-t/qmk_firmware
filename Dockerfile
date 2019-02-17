FROM debian:jessie
MAINTAINER Erik Dasque <erik@frenchguys.com>

RUN apt-get update && apt-get install --no-install-recommends -y build-essential \
    gcc \
    unzip \
    wget \
    zip \
    gcc-avr \
    binutils-avr \
    avr-libc \
    dfu-programmer \
    dfu-util \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    git \
    software-properties-common \
    avrdude \
    curl \
    && rm -rf /var/lib/apt/lists/*

#RUN curl -o /tmp/nrf_sdk.zip https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/nRF5_SDK_15.0.0_a53641a.zip \
#  && unzip /tmp/nrf_sdk.zip -d /dev/nrf \
#  && rm /tmp/nrf_sdk.zip

ENV keyboard=helix_ble
ENV keymap=default
ENV subproject=master
VOLUME /dev/nrf
ENV NRFSDK15_ROOT=/dev/nrf

VOLUME /qmk
WORKDIR /qmk
CMD make clean ; make keyboard=${keyboard} subproject=${subproject} keymap=${keymap}
