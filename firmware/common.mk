SHELL := /bin/bash -O extglob
RACK_DIR ?= ../../..

TARGET_DIR := ../res/firmware/

FLAGS += \
	-DDEBUG \
	-DNULL=0 \
	-DARCH_AVR32=1 \
	-fPIC \
	-fvisibility=hidden \
	-g \
	-Werror=implicit-function-declaration \
	-I../lib/cbbq \

CFLAGS += \
	-std=c99

include $(RACK_DIR)/arch.mk

ifeq ($(ARCH_LIN), 1)
	LDFLAGS += -shared
	TARGET = $(TARGET_DIR)$(TARGET_NAME).so
endif

ifeq ($(ARCH_MAC), 1)
	LDFLAGS += -shared -undefined dynamic_lookup
	TARGET = $(TARGET_DIR)$(TARGET_NAME).dylib
endif

ifeq ($(ARCH_WIN), 1)
	LDFLAGS += -shared 
	TARGET = $(TARGET_DIR)$(TARGET_NAME).dll
endif

include $(RACK_DIR)/compile.mk

all: $(TARGET)

.DEFAULT_GOAL := all