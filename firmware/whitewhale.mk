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
	-Imock_hardware/stubs \
	-Iwhitewhale/libavr32/src \
	-Iwhitewhale/libavr32/src/usb/midi \
	-Iwhitewhale/libavr32/src/usb/hid \
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
	mock_hardware/adapter.c \
	mock_hardware/adapter_trilogy.c \
	mock_hardware/mock_hardware.c \
	mock_hardware/monome.c 

TARGETNAME = ../res/firmware/whitewhale

include $(RACK_DIR)/arch.mk

ifeq ($(ARCH), lin)
	LDFLAGS += -shared
	TARGET = $(TARGETNAME).so
endif

ifeq ($(ARCH), mac)
	LDFLAGS += -shared -undefined dynamic_lookup
	TARGET = $(TARGETNAME).dylib
endif

ifeq ($(ARCH), win)
	LDFLAGS += -shared 
	TARGET = $(TARGETNAME).dll
endif

OBJECTS += $(patsubst %, ../build/firmware/%.o, $(SOURCES))

../build/firmware/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rfv ../build/firmware 