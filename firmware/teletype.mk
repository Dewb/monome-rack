TARGET_NAME := teletype

FLAGS += \
	-D__AVR32_UC3B0512__ \
	-Imock_hardware \
	-Imock_hardware/include \
	-Iteletype/libavr32/src \
	-Iteletype/libavr32/src/usb/midi \
	-Iteletype/libavr32/src/usb/hid \
	-Iteletype/libavr32/src/usb/cdc \
	-Iteletype/libavr32/src/usb/ftdi \
	-Iteletype/libavr32/conf \
	-Iteletype/libavr32/conf/teletype \
	-Iteletype/libavr32/asf/common/services/usb \
	-Iteletype/libavr32/asf/common/services/usb/uhc \
	-Iteletype/libavr32/asf/common/services/usb/class/hid \
	-Iteletype/src \
	-Iteletype/src/ops \
	-Iteletype/ \

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
	teletype/libavr32/src/random.c \
	teletype/libavr32/src/usb/hid/hid.c \
	teletype/libavr32/src/music.c \
	teletype/libavr32/src/midi_common.c \
	$(wildcard teletype/libavr32/src/euclidean/*.c) \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/teletype/*.c) \

SOURCES := $(filter-out teletype/module/usb_disk_mode.c, $(SOURCES))

RAGEL ?= ragel

# Add a rule to build match_token.c from match_token.rl
teletype/src/match_token.c: teletype/src/match_token.rl
	$(RAGEL) -C -G2 teletype/src/match_token.rl -o teletype/src/match_token.c

# Add a rule to build scanner.c from scanner.rl
teletype/src/scanner.c: teletype/src/scanner.rl
	$(RAGEL) -C -G2 teletype/src/scanner.rl -o teletype/src/scanner.c

# Add the git commit id to a file for use when printing out the version
teletype/module/gitversion.c: teletype
	echo "const char *git_version = \"$(shell cut -d '-' -f 1 <<< $(shell cd teletype; git describe --tags | cut -c 1-)) $(shell cd teletype; git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\";" > $@

include common.mk
