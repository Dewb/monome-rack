SLUG = monome
VERSION = 0.6.0


SHELL:=/bin/bash -O extglob
RACK_DIR ?= ../..

FLAGS += \
	-o0 \
	-Werror=implicit-function-declaration \
	-Isrc \
	-Isrc/common \
	-Isrc/common/GridConnection \
	-Isrc/virtualgrid \
	-Isrc/whitewhale \
	-Isrc/meadowphysics \
	-Isrc/earthsea \
	-Ilib/base64 \
	-Ilib/oscpack \
	-Ilib/serialosc 

FLAGS := $(filter-out -MMD,$(FLAGS))

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

ifeq ($(ARCH), win)
	SOURCES += $(wildcard lib/oscpack/ip/win32/*.cpp) 
	LDFLAGS += -lws2_32 -lwinmm
else
	SOURCES += $(wildcard lib/oscpack/ip/posix/*.cpp) 
endif

firmwares:
	cd firmware && $(MAKE) -f whitewhale.mk
	cd firmware && $(MAKE) -f meadowphysics.mk
	cd firmware && $(MAKE) -f earthsea.mk

all: firmwares

# Add files to the ZIP package when running `make dist`
# The compiled plugin is automatically added.
DISTRIBUTABLES += $(wildcard LICENSE*) res firmware

# Include the VCV Rack plugin Makefile framework
include $(RACK_DIR)/plugin.mk