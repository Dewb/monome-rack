SHELL:=/bin/bash -O extglob
RACK_DIR ?= ../..

FLAGS += \
	-Isrc \
	-Isrc/common \
	-Isrc/common/GridConnection \
	-Isrc/virtualgrid \
	-Isrc/whitewhale \
	-Isrc/meadowphysics \
	-Isrc/earthsea \
	-Isrc/teletype \
	-Isrc/teletype-expander \
	-Isrc/ansible \
	-Isrc/faderbank \
	-Ilib/base64 \
	-Ilib/oscpack \
	-Ilib/serialosc \
	-Ifirmware/mock_hardware \

CFLAGS +=
CXXFLAGS += 
LDFLAGS +=

SOURCES += \
	lib/base64/base64.cpp \
	$(wildcard lib/oscpack/ip/*.cpp) \
	$(wildcard lib/oscpack/osc/*.cpp) \
	$(wildcard lib/serialosc/*.cpp) \
	$(wildcard src/*.cpp) \
	$(wildcard src/**/*.cpp) \
	$(wildcard src/**/**/*.cpp) \

include $(RACK_DIR)/arch.mk

ifeq ($(ARCH_WIN), 1)
	SOURCES += $(wildcard lib/oscpack/ip/win32/*.cpp) 
	LDFLAGS += -lws2_32 -lwinmm
else
	SOURCES += $(wildcard lib/oscpack/ip/posix/*.cpp) 
endif

firmwares: firmware/*.mk firmware/**/*.c firmware/**/*.h firmware/**/**/*.rl
	cd firmware && $(MAKE) -f whitewhale.mk
	cd firmware && $(MAKE) -f meadowphysics.mk
	cd firmware && $(MAKE) -f earthsea.mk
	cd firmware && $(MAKE) -f teletype.mk
	cd firmware && $(MAKE) -f ansible.mk

all: firmwares

DISTRIBUTABLES += res
DISTRIBUTABLES += $(wildcard LICENSE*)
DISTRIBUTABLES += $(wildcard presets)

include $(RACK_DIR)/plugin.mk
