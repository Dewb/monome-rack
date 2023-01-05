TARGET_NAME := whitewhale

FLAGS = \
	-D__AVR32_UC3B0256__ \
	-Imock_hardware \
	-Imock_hardware/include \
	-Iwhitewhale/libavr32/src \
	-Iwhitewhale/libavr32/src/usb/midi \
	-Iwhitewhale/libavr32/src/usb/hid \
	-Iwhitewhale/libavr32/src/usb/cdc \
	-Iwhitewhale/libavr32/asf/common/services/usb \
	-Iwhitewhale/libavr32/asf/common/services/usb/uhc \
	-Iwhitewhale/libavr32/conf \
	-Iwhitewhale/libavr32/conf/trilogy \
	
SOURCES = \
	whitewhale/src/main.c \
	whitewhale/libavr32/src/events.c \
	whitewhale/libavr32/src/timers.c \
	whitewhale/libavr32/src/util.c \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/trilogy/*.c) \

FLAGS += -DGIT_VERSION="\"$(shell cut -d '-' -f 1 <<< $(shell cd whitewhale; git describe --tags | cut -c 1-)) $(shell cd whitewhale; git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\""

include common.mk
