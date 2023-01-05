SHELL := /bin/bash -O extglob
RACK_DIR ?= ../../..

TARGET_DIR := ../res/firmware/
BUILD_DIR := ../build/firmware/

FLAGS += \
	-DDEBUG \
	-DNULL=0 \
	-o0 \
	-DARCH_AVR32=1 \
	-fPIC \
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

OBJECTS += $(patsubst %, $(BUILD_DIR)$(TARGET_NAME)/%.o, $(SOURCES))

$(BUILD_DIR)$(TARGET_NAME)/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	echo $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -rfv $(BUILD_DIR)$(TARGET_NAME)
	rm -rfv $(TARGET)

.DEFAULT_GOAL := all