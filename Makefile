SHELL:=/bin/bash -O extglob

FLAGS = \
	-DNULL=0 \
	-o0 \
	-D__AVR32_UC3B0256__ \
	-Werror=implicit-function-declaration \
	-Isrc \
	-Isrc/common \
	-Isrc/grid \
	-Isrc/whitewhale \
	-Isrc/common/mock_hardware \
	-Isrc/common/mock_hardware/stubs \
	-Ilib/base64 \
	-Ilib/oscpack \
	-Ilib/serialosc \
	-Ifirmware/whitewhale/libavr32/src \
	-Ifirmware/whitewhale/libavr32/conf \
	-Ifirmware/whitewhale/libavr32/conf/trilogy \
	
SOURCES = \
	$(wildcard firmware/whitewhale/src/*.c) \
	$(wildcard src/common/mock_hardware/*.c) \
	lib/base64/base64.cpp \
	$(wildcard lib/oscpack/ip/*.cpp) \
	$(wildcard lib/oscpack/osc/*.cpp) \
	$(wildcard lib/serialosc/*.cpp) \
	firmware/whitewhale/libavr32/src/events.c \
	firmware/whitewhale/libavr32/src/timers.c \
	firmware/whitewhale/libavr32/src/monome.c \
	firmware/whitewhale/libavr32/src/util.c \
	$(wildcard src/*.cpp) \
	$(wildcard src/**/*.cpp)

include ../../arch.mk

ifeq ($(ARCH), win)
	SOURCES += $(wildcard lib/oscpack/ip/win32/*.cpp) 
	LDFLAGS += -lws2_32 -lwinmm
else
	SOURCES += $(wildcard lib/oscpack/ip/posix/*.cpp) 
endif

include ../../plugin.mk

FLAGS := $(filter-out -MMD,$(FLAGS))

dist: all
	mkdir -p dist/Monome
	cp LICENSE* dist/Monome/
	cp $(TARGET) dist/Monome/
	cp -R res dist/Monome/