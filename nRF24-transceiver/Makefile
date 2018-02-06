# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

ARDUINO = /usr/share/arduino
ARDUINO_DIR = $(ARDUINO)
ARDUINO_SKETCHBOOK = $(PWD)
ARDUINO_LIBS = RF24
ARDMK_VENDOR = archlinux-arduino
ARCHITECTURE = avr
MCU = atmega328p
BOARD_TAG = nano
AVRDUDE_ARD_BAUDRATE = 57600

include $(ARDUINO)/Arduino.mk

.PHONY: all

all: libraries/RF24

libraries:
	mkdir -p $@

libraries/RF24: libraries
	git clone git@github.com:nRF24/RF24.git $@
