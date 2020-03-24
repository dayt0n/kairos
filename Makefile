all:
	gcc main.c patchfinder64.c newpatch.c decoders.c instructions.c -Iinclude -o kairos
clean:
	rm kairos
