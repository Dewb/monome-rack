SHELL:=/bin/bash -O extglob

FLAGS = \
	-o0 \
	-Werror=implicit-function-declaration \
	-Isrc \
	-Isrc/common \
	-Isrc/grid \
	-Isrc/whitewhale \
	-Isrc/meadowphysics \
	-Ilib/base64 \
	-Ilib/oscpack \
	-Ilib/serialosc 

SOURCES = \
	lib/base64/base64.cpp \
	$(wildcard lib/oscpack/ip/*.cpp) \
	$(wildcard lib/oscpack/osc/*.cpp) \
	$(wildcard lib/serialosc/*.cpp) \
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

firmwares:
	cd firmware && $(MAKE) -f whitewhale.mk
	cd firmware && $(MAKE) -f meadowphysics.mk

all: firmwares

dist: all
	mkdir -p dist/Monome
	cp LICENSE* dist/Monome/
	cp $(TARGET) dist/Monome/
	cp -R res dist/Monome/