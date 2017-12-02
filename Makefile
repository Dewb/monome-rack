FLAGS = \
	-DNULL=0 \
	-o0 \
	-D__AVR32_UC3B0256__ \
	-Werror=implicit-function-declaration \
	-Irack \
	-Irack/mock_hardware \
	-Irack/mock_hardware/stubs \
	-Irack/lib/base64 \
	-Irack/lib/oscpack \
	-Irack/lib/serialosc \
	-Ilibavr32/src \
	-Ilibavr32/conf \
	-Ilibavr32/conf/trilogy \
	-Isrc
	
SOURCES = \
	$(wildcard src/*.c) \
	$(wildcard rack/mock_hardware/*.c) \
	rack/lib/base64/base64.cpp \
	$(wildcard rack/lib/oscpack/ip/*.cpp) \
	$(wildcard rack/lib/oscpack/osc/*.cpp) \
	$(wildcard rack/lib/serialosc/*.cpp) \
	libavr32/src/events.c \
	libavr32/src/timers.c \
	libavr32/src/monome.c \
	libavr32/src/util.c \
	$(wildcard rack/*.cpp)

include ../../arch.mk

ifeq ($(ARCH), win)
	SOURCES += $(wildcard rack/lib/oscpack/ip/win32/*.cpp) 
	LDFLAGS += -lws2_32 -lwinmm
else
	SOURCES += $(wildcard rack/lib/oscpack/ip/posix/*.cpp) 
endif

include ../../plugin.mk

FLAGS := $(filter-out -MMD,$(FLAGS))

dist: all
	mkdir -p dist/Monome
	cp LICENSE* dist/Monome/
	cp $(TARGET) dist/Monome/
	cp -R res dist/Monome/