.SUFFIXES:

CCW32=i686-w64-mingw32-gcc
CCW64=x86_64-w64-mingw32-gcc

EXT=
ifeq ($(OS),Windows_NT)
EXT=.exe
endif

.PHONY: all clean
all: deinterleaver$(EXT) interleaver$(EXT)

%$(EXT): %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

%32.exe: %.c
	$(CCW32) $(CPPFLAGS) $(CFLAGS) $< -o $@

%64.exe: %.c
	$(CCW64) $(CPPFLAGS) $(CFLAGS) $< -o $@

clean:
	$(RM) deinterleaver$(EXT) interleaver$(EXT)