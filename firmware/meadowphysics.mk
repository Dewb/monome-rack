TARGET_NAME := meadowphysics

FLAGS += \
	-D__AVR32_UC3B0256__ \
	-Imock_hardware \
	-Imock_hardware/include \
	-Imeadowphysics/libavr32/src \
	-Imeadowphysics/libavr32/src/usb/midi \
	-Imeadowphysics/libavr32/src/usb/hid \
	-Imeadowphysics/libavr32/src/usb/cdc \
	-Imeadowphysics/libavr32/asf/common/services/usb \
	-Imeadowphysics/libavr32/asf/common/services/usb/uhc \
	-Imeadowphysics/libavr32/conf \
	-Imeadowphysics/libavr32/conf/trilogy \
		
SOURCES = \
	meadowphysics/src/main.c \
	meadowphysics/libavr32/src/events.c \
	meadowphysics/libavr32/src/timers.c \
	meadowphysics/libavr32/src/util.c \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/trilogy/*.c) \

FLAGS += -DGIT_VERSION="\"$(shell cut -d '-' -f 1 <<< $(shell cd meadowphysics; git describe --tags | cut -c 1-)) $(shell cd meadowphysics; git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\""

include common.mk
