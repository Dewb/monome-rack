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
	-Imeadowphysics/libavr32/src \
	-Imeadowphysics/libavr32/src/usb/midi \
	-Imeadowphysics/libavr32/src/usb/hid \
	-Imeadowphysics/libavr32/src/usb/cdc \
	-Imeadowphysics/libavr32/asf/common/services/usb \
	-Imeadowphysics/libavr32/asf/common/services/usb/uhc \
	-Imeadowphysics/libavr32/conf \
	-Imeadowphysics/libavr32/conf/trilogy \

CFLAGS += \
	-std=c99
		
SOURCES = \
	meadowphysics/src/main.c \
	meadowphysics/libavr32/src/events.c \
	meadowphysics/libavr32/src/timers.c \
	meadowphysics/libavr32/src/util.c \
	$(wildcard mock_hardware/mock_hardware_api.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/trilogy/*.c) \

TARGETNAME = ../res/firmware/meadowphysics

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

OBJECTS += $(patsubst %, ../build/firmware/meadowphysics/%.o, $(SOURCES))

../build/firmware/meadowphysics/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rfv ../build/firmware/meadowphysics