.DEFAULT_GOAL := all

SHELL:=/bin/bash -O extglob

FLAGS = \
	-DNULL=0 \
	-o0 \
	-D__AVR32_UC3B0512__ \
	-fPIC \
	-g \
	-Werror=implicit-function-declaration \
	-Imock_hardware \
	-Imock_hardware/stubs \
	-Iteletype/libavr32/src \
	-Iteletype/libavr32/src/usb/midi \
	-Iteletype/libavr32/src/usb/hid \
	-Iteletype/libavr32/conf \
	-Iteletype/libavr32/conf/teletype \
	-Iteletype/libavr32/asf/common/services/usb \
	-Iteletype/libavr32/asf/common/services/usb/uhc \
	-Iteletype/libavr32/asf/common/services/usb/class/hid \
	-Iteletype/src \
	-Iteletype/src/ops
	
CFLAGS += \
	-std=c99

SOURCES = \
	$(wildcard teletype/src/*.c) \
	teletype/src/scanner.c \
	teletype/src/match_token.c \
	teletype/module/gitversion.c \
	$(wildcard teletype/src/ops/*.c) \
	$(wildcard teletype/module/*.c) \
	teletype/libavr32/src/events.c \
	teletype/libavr32/src/timers.c \
	teletype/libavr32/src/util.c \
	teletype/libavr32/src/font.c \
	teletype/libavr32/src/kbd.c \
	teletype/libavr32/src/region.c \
	teletype/libavr32/src/usb/hid/hid.c \
	$(wildcard teletype/libavr32/src/euclidean/*.c) \
	mock_hardware/adapter.c \
	mock_hardware/mock_hardware.c \
	mock_hardware/monome.c

SOURCES := $(filter-out teletype/module/usb_disk_mode.c, $(SOURCES))

TARGETNAME = ../res/firmware/teletype

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

OBJECTS += $(patsubst %, ../build/firmware/teletype/%.o, $(SOURCES))

# Add a rule to build match_token.c from match_token.rl
teletype/src/match_token.c: teletype/src/match_token.rl
	ragel -C -G2 teletype/src/match_token.rl -o teletype/src/match_token.c

# Add a rule to build scanner.c from scanner.rl
teletype/src/scanner.c: teletype/src/scanner.rl
	ragel -C -G2 teletype/src/scanner.rl -o teletype/src/scanner.c

# Add the git commit id to a file for use when printing out the version
teletype/module/gitversion.c: teletype
	echo "const char *git_version = \"$(shell cd teletype; git describe --always --dirty | tr '[a-z]' '[A-Z]')\";" > $@


../build/firmware/teletype/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

all: $(TARGET) 

clean:
	rm -rfv ../build/firmware/teletype