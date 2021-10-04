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
	-Iearthsea/libavr32/src \
	-Iearthsea/libavr32/src/usb/midi \
	-Iearthsea/libavr32/src/usb/hid \
	-Iearthsea/libavr32/src/usb/cdc \
	-Iearthsea/libavr32/asf/common/services/usb \
	-Iearthsea/libavr32/asf/common/services/usb/uhc \
	-Iearthsea/libavr32/conf \
	-Iearthsea/libavr32/conf/trilogy \
	
CFLAGS += \
	-std=c99
	
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

TARGETNAME = ../res/firmware/earthsea

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

OBJECTS += $(patsubst %, ../build/firmware/earthsea/%.o, $(SOURCES))

FLAGS += -DGIT_VERSION="\"$(shell cut -d '-' -f 1 <<< $(shell cd earthsea; git describe --tags | cut -c 1-)) $(shell cd earthsea; git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\""

../build/firmware/earthsea/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rfv ../build/firmware/earthsea