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
	-Iearthsea/libavr32/src \
	-Iearthsea/libavr32/src/usb/midi \
	-Iearthsea/libavr32/conf \
	-Iearthsea/libavr32/conf/trilogy \
	
SOURCES = \
	earthsea/src/main.c \
	earthsea/libavr32/src/arp.c \
	earthsea/libavr32/src/euclidean/data.c \
	earthsea/libavr32/src/euclidean/euclidean.c \
	earthsea/libavr32/src/events.c \
	earthsea/libavr32/src/monome.c \
	earthsea/libavr32/src/notes.c \
	earthsea/libavr32/src/random.c \
	earthsea/libavr32/src/timers.c \
	earthsea/libavr32/src/util.c \
	mock_hardware/adapter.c \
	mock_hardware/mock_hardware.c

TARGETNAME = ../build/firmware/earthsea

include ../../../arch.mk

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
	$(CXX) -o $@ $^ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rfv ../build/firmware 