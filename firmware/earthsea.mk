TARGET_NAME := earthsea

FLAGS = \
	-D__AVR32_UC3B0256__ \
	-Imock_hardware \
	-Imock_hardware/include \
	-Iearthsea/libavr32/src \
	-Iearthsea/libavr32/src/usb/midi \
	-Iearthsea/libavr32/src/usb/hid \
	-Iearthsea/libavr32/src/usb/cdc \
	-Iearthsea/libavr32/asf/common/services/usb \
	-Iearthsea/libavr32/asf/common/services/usb/uhc \
	-Iearthsea/libavr32/conf \
	-Iearthsea/libavr32/conf/trilogy \
	
SOURCES = \
	earthsea/src/main.c \
	earthsea/libavr32/src/arp.c \
	earthsea/libavr32/src/euclidean/data.c \
	earthsea/libavr32/src/euclidean/euclidean.c \
	earthsea/libavr32/src/events.c \
	earthsea/libavr32/src/notes.c \
	earthsea/libavr32/src/random.c \
	earthsea/libavr32/src/timers.c \
	earthsea/libavr32/src/util.c \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/trilogy/*.c) \

FLAGS += -DGIT_VERSION="\"$(shell cut -d '-' -f 1 <<< $(shell cd earthsea; git describe --tags | cut -c 1-)) $(shell cd earthsea; git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\""

include common.mk
