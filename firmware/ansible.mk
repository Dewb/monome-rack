TARGET_NAME := ansible

FLAGS += \
	-D__AVR32_UC3B0256__ \
	-Imock_hardware \
	-Imock_hardware/include \
	-Iansible/libavr32/src \
	-Iansible/libavr32/src/usb/midi \
	-Iansible/libavr32/src/usb/hid \
	-Iansible/libavr32/src/usb/cdc \
	-Iansible/libavr32/src/usb/ftdi \
	-Iansible/libavr32/asf/common/services/usb \
	-Iansible/libavr32/asf/common/services/usb/uhc \
	-Iansible/libavr32/conf \
	-Iansible/libavr32/conf/trilogy \
	-Iansible/src
		
SOURCES = \
	ansible/src/main.c \
	ansible/src/ansible_grid.c    \
	ansible/src/ansible_arc.c    \
	ansible/src/ansible_midi.c    \
	ansible/src/ansible_tt.c    \
	ansible/src/ansible_preset_docdef.c    \
	ansible/src/ansible_ii_leader.c    \
	ansible/src/gitversion.c    \
	ansible/libavr32/src/arp.c     \
	ansible/libavr32/src/dac.c     \
	ansible/libavr32/src/euclidean/data.c \
	ansible/libavr32/src/euclidean/euclidean.c \
	ansible/libavr32/src/events.c \
	ansible/libavr32/src/libfixmath/fix16.c     \
	ansible/libavr32/src/timers.c \
	ansible/libavr32/src/util.c \
	ansible/libavr32/src/json/encoding.c \
	ansible/libavr32/src/json/serdes.c \
	ansible/libavr32/src/json/jsmn/jsmn.c \
	ansible/libavr32/src/random.c \
	ansible/libavr32/src/music.c \
	ansible/libavr32/src/midi_common.c \
	ansible/libavr32/src/music.c \
	ansible/libavr32/src/notes.c \
	ansible/libavr32/src/random.c \
	$(wildcard mock_hardware/*.c) \
	$(wildcard mock_hardware/common/*.c) \
	$(wildcard mock_hardware/modules/ansible/*.c) \

# Add the git commit id to a file for use when printing out the version
ansible/src/gitversion.c: ansible
	echo "const char *git_version = \"$(shell cut -d '-' -f 1 <<< $(shell cd ansible; git describe --tags | cut -c 1-)) $(shell cd ansible; git describe --always --dirty --exclude '*' | tr '[a-z]' '[A-Z]')\";" > $@

include common.mk
