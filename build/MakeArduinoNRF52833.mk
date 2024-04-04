#Arduino root directory

ARDUINO_ROOT_DIR = $(LIB_ROOT_DIR)/Arduino/
ARDUINO_CORE_AVR_DIR = $(LIB_ROOT_DIR)/Arduino/cores/avr
ARDUINO_CORE_NRF_DIR = $(LIB_ROOT_DIR)/Arduino/cores/nRF5
ARDUINO_LIBS_DIR = $(LIB_ROOT_DIR)/Arduino/libraries
ARDUINO_LIB_TINYUSB_DIR = $(LIB_ROOT_DIR)/Arduino/libraries/Adafruit_TinyUSB_Arduino/src
ARDUINO_LIB_LITTLE_FS_DIR = $(LIB_ROOT_DIR)/Arduino/libraries/Adafruit_LittleFS/src
ARDUINO_LIB_INTERNAL_FS_DIR = $(LIB_ROOT_DIR)/Arduino/libraries/InternalFileSytem/src
ARDUINO_LIB_BLUEFRUIT_DIR = $(LIB_ROOT_DIR)/Arduino/libraries/Bluefruit52Lib/src

DEFINES += -DARDUINO_NRF52_ADAFRUIT
DEFINES += -DARDUINO_ARCH_NRF52
DEFINES += -DARDUINO=10804
DEFINES += -DCFG_DEBUG=0
DEFINES += -DLFS_NO_ASSERT
DEFINES += -DUSE_LFXO
DEFINES += -DDEFY_NRF52
DEFINES += -DUSBCON

INCDIR += -I$(ARDUINO_CORE_NRF_DIR)/
SRCSC += $(wildcard $(ARDUINO_CORE_NRF_DIR)/*.c)
SRCSCXX += $(wildcard $(ARDUINO_CORE_NRF_DIR)/*.cpp)

INCDIR += -I$(ARDUINO_CORE_AVR_DIR)/


#Tiny usb
ARDUINO_LIB_TINYUSB_DIR = $(LIB_ROOT_DIR)/Arduino/libraries/Adafruit_TinyUSB_Arduino/src
DEFINES += -DUSECON
DEFINES += -DUSE_TINYUSB

INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/utility
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/osal
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/net
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/video
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/msc
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/midi
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/bth
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/vendor
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/hid
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/dfu
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/usbtmc
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/audio
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/class/cdc
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/device
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/common
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/host
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino/msc
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino/webusb
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino/ports
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino/ports/nrf
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino/midi
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino/hid
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/arduino/cdc
INCDIR += -I$(ARDUINO_LIB_TINYUSB_DIR)/portable/nordic/nrf5x

SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/utility/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/osal/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/net/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/video/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/msc/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/midi/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/bth/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/vendor/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/hid/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/dfu/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/usbtmc/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/audio/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/cdc/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/device/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/common/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/host/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/msc/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/webusb/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/ports/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/ports/nrf/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/midi/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/hid/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/cdc/*.c)
SRCSC += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/portable/nordic/nrf5x/*.c)

SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/utility/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/osal/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/net/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/video/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/msc/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/midi/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/bth/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/vendor/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/hid/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/dfu/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/usbtmc/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/audio/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/class/cdc/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/device/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/common/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/host/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/msc/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/webusb/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/ports/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/ports/nrf/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/midi/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/hid/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/arduino/cdc/*.cpp)
SRCSCXX += $(wildcard $(ARDUINO_LIB_TINYUSB_DIR)/portable/nordic/nrf5x/*.cpp)