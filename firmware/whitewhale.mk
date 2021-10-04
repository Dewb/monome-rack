.DEFAULT_GOAL := all

SHELL:=/bin/bash -O extglob

FLAGS = \
	-DNULL=0 \
	-o0 \
	-D__AVR32_UC3B0256__ \
	-fPIC \
	-g \
	-Werror=implicit-function-declaration \
	-Imock_hardware \
	-Imock_hardware/include \
	-I../lib/cbbq \
	-Iwhitewhale/libavr32/src \
	-Iwhitewhale/libavr32/src/usb/midi \
	-Iwhitewhale/libavr32/src/usb/hid \
	-Iwhitewhale/libavr32/src/usb/cdc \
	-Iwhitewhale/libavr32/asf/common/services/usb \
	-Iwhitewhale/libavr32/asf/common/services/usb/uhc \
	-Iwhitewhale/libavr32/conf \
	-Iwhitewhale/libavr32/conf/trilogy \
	
CFLAGS += \
	-std=c99
	
SOURCES = \
	whitewhale/src/main.c \
	whitewhale/libavr32/src/events.c \
	whitewhale/libavr32/src/timers.c \
	whitewhale/libavr32/src/util.c \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/trilogy/*.c) \

TARGETNAME = ../res/firmware/whitewhale

include $(RACK_DIR)/arch.mk

ifeq ($(ARCH_LIN), 1)
	LDFLAGS += -shared
	TARGET = $(TARGETNAME).so
endif

ifeq ($(ARCH_MAC), 1)
	LDFLAGS += -shared -undefined dynamic_lookup
	TARGET = $(TARGETNAME).dylib
endif

ifeq ($(ARCH_WIN), 1)
	LDFLAGS += -shared 
	TARGET = $(TARGETNAME).dll
endif

OBJECTS += $(patsubst %, ../build/firmware/whitewhale/%.o, $(SOURCES))

FLAGS += -DGIT_VERSION="\"$(shell cut -d '-' -f 1 <<< $(shell cd whitewhale; git describe --tags | cut -c 1-)) $(shell cd whitewhale; git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\""

../build/firmware/whitewhale/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rfv ../build/firmware/whitewhale