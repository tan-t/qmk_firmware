#!/bin/bash

NRFUTIL="nrfutil"
GREP="grep"
TARGET="$1"

echo "NRFUTIL=${NRFUTIL}"
echo "TARGET=${TARGET}"
echo "GREP=${GREP}"

if ! type "nrfutil" > /dev/null 2>&1; then \
        echo 'ERROR: nrfutil is not found'; exit 1;\
fi
${NRFUTIL} pkg generate --debug-mode --hw-version 52 --sd-req 0xA9 --application ${TARGET}.bin ${TARGET}.zip


if ${GREP} -q -s Microsoft /proc/version; then \
    echo 'ERROR: nrfutil cannot be automated within the Windows Subsystem for Linux (WSL) currently.'; \
else \
    printf "Detecting USB port, put your controller into dfu-mode now."; \
                ls /dev/tty* > /tmp/1; \
                while [ -z $USB ]; do \
                        sleep 0.5; \
                        printf "."; \
                        ls /dev/tty* > /tmp/2; \
                        USB=`comm -13 /tmp/1 /tmp/2 | ${GREP} -o '/dev/tty.*'`; \
                        mv /tmp/2 /tmp/1; \
                done; \
                echo ""; \
                echo "Detected controller on USB port at $USB"; \
                if ${GREP} -q -s 'MINGW\|MSYS' /proc/version; then \
                        USB=`echo "$USB" | perl -pne 's/\/dev\/ttyS(\d+)/COM.($1+1)/e'`; \
                        echo "Remapped MSYS2 USB port to $USB"; \
                fi; \
                sleep 1; \
                echo "Programming Started"; \
                ${NRFUTIL} dfu usb-serial -pkg ${TARGET}.zip -p $USB; \
fi