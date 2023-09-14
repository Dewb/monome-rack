# Rack SDK compile.mk modified to support configurable build products folder

ifndef RACK_DIR
$(error RACK_DIR is not defined)
endif

include $(RACK_DIR)/arch.mk

BUILD_DIR ?= build
OBJCOPY ?= objcopy
STRIP ?= strip
INSTALL_NAME_TOOL ?= install_name_tool
OTOOL ?= otool

# Generate dependency files alongside the object files
FLAGS += -MMD -MP
# Debugger symbols. These are removed with `strip`.
FLAGS += -g
# Optimization
FLAGS += -O3 -funsafe-math-optimizations -fno-omit-frame-pointer
# Warnings
FLAGS += -Wall -Wextra -Wno-unused-parameter
# C++ standard
CXXFLAGS += -std=c++11

# Define compiler/linker target if cross-compiling
ifdef CROSS_COMPILE
	FLAGS += --target=$(MACHINE)
	LDFLAGS += --target=$(MACHINE)
endif

# Architecture-independent flags
ifdef ARCH_X64
	FLAGS += -DARCH_X64
	FLAGS += -march=nehalem
endif
ifdef ARCH_ARM64
	FLAGS += -DARCH_ARM64
	FLAGS += -march=armv8-a+fp+simd
endif

ifdef ARCH_LIN
	FLAGS += -DARCH_LIN
	CXXFLAGS += -Wsuggest-override
endif
ifdef ARCH_MAC
	FLAGS += -DARCH_MAC
	CXXFLAGS += -stdlib=libc++
	LDFLAGS += -stdlib=libc++
	MAC_SDK_FLAGS := -mmacosx-version-min=10.9
	FLAGS += $(MAC_SDK_FLAGS)
	LDFLAGS += $(MAC_SDK_FLAGS)
endif
ifdef ARCH_WIN
	FLAGS += -DARCH_WIN
	FLAGS += -D_USE_MATH_DEFINES
	FLAGS += -municode
	CXXFLAGS += -Wsuggest-override
endif

# Allow *appending* rather than prepending to common flags.
# This is useful to force-redefine compiler settings instead of merely setting defaults that may be overwritten.
FLAGS += $(EXTRA_FLAGS)
CFLAGS += $(EXTRA_CFLAGS)
CXXFLAGS += $(EXTRA_CXXFLAGS)
LDFLAGS += $(EXTRA_LDFLAGS)

# Apply FLAGS to language-specific flags
CFLAGS += $(FLAGS)
CXXFLAGS += $(FLAGS)

# Derive object files from sources and place them before user-defined objects
OBJECTS := $(patsubst %, $(BUILD_DIR)/%.o, $(SOURCES)) $(OBJECTS)
OBJECTS += $(patsubst %, $(BUILD_DIR)/%.bin.o, $(BINARIES))
DEPENDENCIES := $(patsubst %, $(BUILD_DIR)/%.d, $(SOURCES))

# Final targets

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

-include $(DEPENDENCIES)

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.cc.o: %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.m.o: %.m
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.bin.o: %
	@mkdir -p $(@D)
ifdef ARCH_LIN
	$(OBJCOPY) -I binary -O elf64-x86-64 -B i386:x86-64 --rename-section .data=.rodata,alloc,load,readonly,data,contents $< $@
endif
ifdef ARCH_WIN
	$(OBJCOPY) -I binary -O pe-x86-64 -B i386:x86-64 --rename-section .data=.rodata,alloc,load,readonly,data,contents $< $@
endif
ifdef ARCH_MAC
	@# Apple makes this needlessly complicated, so just generate a C file with an array.
	xxd -i $< | $(CC) $(MAC_SDK_FLAGS) -c -o $@ -xc -
endif

$(BUILD_DIR)/%.html: %.md
	markdown $< > $@
