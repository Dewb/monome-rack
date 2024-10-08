SHELL:=/bin/bash -O extglob
RACK_DIR ?= ../..

FLAGS += \
	-Isrc \
	-Isrc/common \
	-Isrc/common/core \
	-Isrc/common/util \
	-Isrc/common/widgets \
	-Isrc/common/core/GridConnection \
	-Isrc/virtualgrid \
	-Isrc/whitewhale \
	-Isrc/meadowphysics \
	-Isrc/earthsea \
	-Isrc/teletype \
	-Isrc/ansible \
	-Isrc/faderbank \
	-Ilib/base64 \
	-Ilib/oscpack \
	-Ilib/serialosc \
	-Ilib/simple-svg \
	-Ifirmware/mock_hardware \
	-g \

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
	$(wildcard src/**/**/**/*.cpp) \

include $(RACK_DIR)/arch.mk

ifeq ($(ARCH_WIN), 1)
	SOURCES += $(wildcard lib/oscpack/ip/win32/*.cpp) 
	LDFLAGS += -lws2_32 -lwinmm -lopengl32
else
	SOURCES += $(wildcard lib/oscpack/ip/posix/*.cpp) 
endif

# Dependencies
ragel := dep/bin/ragel
DEPS += $(ragel)

$(ragel):
	$(WGET) http://www.colm.net/files/ragel/ragel-6.10.tar.gz
	cd dep && $(UNTAR) ../ragel-6.10.tar.gz
	# Temporarily override the cross-compilation build flags to build ragel on build host (since we don't want to cross-compile it).
	cd dep/ragel-6.10 && CC=gcc CXX=g++ STRIP=strip FLAGS= CFLAGS= CXXFLAGS= LDFLAGS= ./configure --prefix="$(DEP_PATH)"
	cd dep/ragel-6.10 && $(MAKE) && $(MAKE) install

firmware-build: export PATH := $(PWD)/dep/bin:$(PATH)
firmware-build: export RACK_DIR := $(realpath $(RACK_DIR))
firmware-build:
	cd firmware && $(MAKE) -f whitewhale.mk TARGET_NAME=whitewhale GIT_VERSION="v1.5 6CD668C"
	cd firmware && $(MAKE) -f whitewhale.mk TARGET_NAME=whitewhale-kria GIT_VERSION="v0.4 1E0E2FB"
	cd firmware && $(MAKE) -f meadowphysics.mk GIT_VERSION="v2.1 39A2139"
	cd firmware && $(MAKE) -f earthsea.mk GIT_VERSION="v1.9.4 4B88B2E"
	cd firmware && $(MAKE) -f ansible.mk GIT_VERSION="v1.5.0 6EEF788"
	cd firmware && $(MAKE) -f teletype.mk TARGET_NAME=teletype4 GIT_VERSION="v4.0.0 A34DA87"
	cd firmware && $(MAKE) -f teletype.mk TARGET_NAME=teletype5 GIT_VERSION="v5.0.0 00F5FD2"

firmware-clean:
	rm -fv res/firmware/*.dll
	rm -fv res/firmware/*.dylib
	rm -fv res/firmware/*.so

DISTRIBUTABLES += $(wildcard res)
DISTRIBUTABLES += $(wildcard LICENSE*)
DISTRIBUTABLES += $(wildcard presets)

include $(RACK_DIR)/plugin.mk

all: firmware-build

clean: firmware-clean
