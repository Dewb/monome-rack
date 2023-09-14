FLAGS += \
	-D__AVR32_UC3B0256__ \
	-Imock_hardware \
	-Imock_hardware/include \
	-I$(TARGET_NAME)/libavr32/src \
	-I$(TARGET_NAME)/libavr32/src/usb/midi \
	-I$(TARGET_NAME)/libavr32/src/usb/hid \
	-I$(TARGET_NAME)/libavr32/src/usb/cdc \
	-I$(TARGET_NAME)/libavr32/asf/common/services/usb \
	-I$(TARGET_NAME)/libavr32/asf/common/services/usb/uhc \
	-I$(TARGET_NAME)/libavr32/conf \
	-I$(TARGET_NAME)/libavr32/conf/trilogy \
	
SOURCES = \
	$(TARGET_NAME)/src/main.c \
	$(TARGET_NAME)/libavr32/src/events.c \
	$(TARGET_NAME)/libavr32/src/timers.c \
	$(TARGET_NAME)/libavr32/src/util.c \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/trilogy/*.c) \

FLAGS += -DGIT_VERSION="\"$(shell cut -d '-' -f 1 <<< $(shell cd $(TARGET_NAME); git describe --tags | cut -c 1-)) $(shell cd $(TARGET_NAME); git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\""

include common.mk
