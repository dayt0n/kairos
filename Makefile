ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo unknown')
endif

all:
ifeq ($(detected_OS),Darwin)
		gcc main.c patchfinder64.c newpatch.c decoders.c instructions.c -Iinclude -o kairos
else
		gcc main.c patchfinder64.c newpatch.c decoders.c instructions.c -Iinclude -DNOT_DARWIN -o kairos
endif
clean:
ifeq ($(detected_OS),Windows)
		rm kairos.exe
else
		rm kairos
endif