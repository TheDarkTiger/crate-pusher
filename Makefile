# Hi and thx KAB!

#Custom Values
ROM_NAME=CRATEPUSHER

GBDK=D:/DEV_GB/GBDK
FLASHER=D:/DEV_GB/tools/GBxCartRW/flash $(CURDIR)/build/$(ROM_NAME).gb

#Files
ISRC=$(wildcard src/*.c)
IASM=$(wildcard src/*.s)
ILIB=$(wildcard src/lib/*.lib)

OBJ_C=$(ISRC:src/%.c=build/%.o)
OBJ_ASM=$(IASM:src/%.s=build/%.o)

#Flags
FLAGS=-Wf-Isrc/include \
-Wf-Isrc \
-Wa-l \
-Wl-m -Wl-w -Wl-j \
-Wm-yt0 -Wm-ya0 -Wm-yS -Wm-yn$(ROM_NAME)

ifeq ($(RELEASE), 1)
	FLAGS+=-Wf--max-allocs-per-node50000
endif

all: build/$(ROM_NAME).gb

$(OBJ_C): build/%.o : src/%.c
	@echo -----------------------------------Compiling $<
	@$(GBDK)/bin/lcc $(FLAGS) -c -o $@ $<

$(OBJ_ASM): build/%.o : src/%.s
	@echo Assembling $<
	@$(GBDK)/bin/lcc $(FLAGS) -c -o $@ $<

build/$(ROM_NAME).gb: $(OBJ_C) $(OBJ_ASM) $(ILIB)
	@echo Making ROM $(ROM_NAME).gb
	@$(GBDK)/bin/lcc $(FLAGS) -o $@ $^
	@echo Done

clean:
#	@rm -f build/*.*
	@del /F /S /Q build
	@echo Cleaned

upload:
	@$(FLASHER)

usage:
	@$(GBDK)/bin/romusage build/$(ROM_NAME).map -g -sC
