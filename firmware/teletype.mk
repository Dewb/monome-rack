FLAGS += \
	-D__AVR32_UC3B0512__ \
	-Imock_hardware \
	-Imock_hardware/include \
	-I$(TARGET_NAME)/libavr32/src \
	-I$(TARGET_NAME)/libavr32/src/usb/midi \
	-I$(TARGET_NAME)/libavr32/src/usb/hid \
	-I$(TARGET_NAME)/libavr32/src/usb/cdc \
	-I$(TARGET_NAME)/libavr32/src/usb/ftdi \
	-I$(TARGET_NAME)/libavr32/conf \
	-I$(TARGET_NAME)/libavr32/conf/teletype \
	-I$(TARGET_NAME)/libavr32/asf/common/services/usb \
	-I$(TARGET_NAME)/libavr32/asf/common/services/usb/uhc \
	-I$(TARGET_NAME)/libavr32/asf/common/services/usb/class/hid \
	-I$(TARGET_NAME)/src \
	-I$(TARGET_NAME)/src/ops \
	-I$(TARGET_NAME)/ \

SOURCES = \
	$(wildcard $(TARGET_NAME)/src/*.c) \
	$(TARGET_NAME)/src/scanner.c \
	$(TARGET_NAME)/src/match_token.c \
	$(TARGET_NAME)/module/gitversion.c \
	$(wildcard $(TARGET_NAME)/src/ops/*.c) \
	$(wildcard $(TARGET_NAME)/module/*.c) \
	$(TARGET_NAME)/libavr32/src/events.c \
	$(TARGET_NAME)/libavr32/src/timers.c \
	$(TARGET_NAME)/libavr32/src/util.c \
	$(TARGET_NAME)/libavr32/src/font.c \
	$(TARGET_NAME)/libavr32/src/kbd.c \
	$(TARGET_NAME)/libavr32/src/region.c \
	$(TARGET_NAME)/libavr32/src/random.c \
	$(TARGET_NAME)/libavr32/src/usb/hid/hid.c \
	$(TARGET_NAME)/libavr32/src/music.c \
	$(TARGET_NAME)/libavr32/src/midi_common.c \
	$(wildcard $(TARGET_NAME)/libavr32/src/euclidean/*.c) \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/teletype/*.c) \

SOURCES := $(filter-out $(TARGET_NAME)/module/usb_disk_mode.c, $(SOURCES))

RAGEL ?= ragel

# Add a rule to build match_token.c from match_token.rl
$(TARGET_NAME)/src/match_token.c: $(TARGET_NAME)/src/match_token.rl
	$(RAGEL) -C -G2 $(TARGET_NAME)/src/match_token.rl -o $(TARGET_NAME)/src/match_token.c

# Add a rule to build scanner.c from scanner.rl
$(TARGET_NAME)/src/scanner.c: $(TARGET_NAME)/src/scanner.rl
	$(RAGEL) -C -G2 $(TARGET_NAME)/src/scanner.rl -o $(TARGET_NAME)/src/scanner.c

# Add the git commit id to a file for use when printing out the version
$(TARGET_NAME)/module/gitversion.c: $(TARGET_NAME)
	echo "const char *git_version = \"$(GIT_VERSION)\";" > $@

include common.mk
