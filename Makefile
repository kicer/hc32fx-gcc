## Set Mcu Type
DEVICE=hc32f005x6
MCPU=cortex-m0

## A directory for common include files
BSP = bsp

## Get program name from enclosing directory name
APP = objects/$(lastword $(subst /, ,$(CURDIR)))

SOURCES  = $(wildcard src/*.c) $(wildcard bsp/*.c)
OBJECTS  = $(SOURCES:.c=.o)
OBJECTS += startup/core.o
OBJECTS += startup/$(DEVICE)_vt.o

HEADERS=$(wildcard src/inc/*.h $(BSP)/inc/*.h)

TOOLCHAIN ?= /Developer/gcc-arm-none-eabi
CC = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
AS = $(TOOLCHAIN)/bin/arm-none-eabi-as
LD = $(TOOLCHAIN)/bin/arm-none-eabi-ld
OC = $(TOOLCHAIN)/bin/arm-none-eabi-objcopy
OD = $(TOOLCHAIN)/bin/arm-none-eabi-objdump
OS = $(TOOLCHAIN)/bin/arm-none-eabi-size

APPFLAGS = -I$(BSP)/inc -Isrc/inc

ASMFLAGS += -c -O0 -mcpu=$(MCPU) -mthumb -Wall
ASMFLAGS += -fmessage-length=0

CFLAGS += -mthumb -mcpu=$(MCPU) -Os -Wall -MD
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += --specs=nosys.specs -fno-exceptions
CFLAGS += -fmessage-length=0
CFLAGS += -msoft-float -mfloat-abi=soft
CFLAGS += -D$(DEVICE)

LDFLAGS += -mthumb -mcpu=$(MCPU) -Wl,-cref -Wl,--gc-sections
LDFLAGS += -L./ld -T./ld/$(DEVICE).ld
LDFLAGS += -Wl,-Map=$(APP).map


.PHONY: all clean

all: $(APP).hex $(APP).bin
$(APP).bin $(APP).hex: $(APP).elf

%.bin: %.elf
	$(OC) -S -O binary $< $@
	$(OS) $<

%.hex: %.elf
	$(OC) -S -O ihex $< $@

$(APP).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(APPFLAGS) -c -o $@ $<

%.o: %.S
	$(CC) $(ASMFLAGS) -o $@ -c $<

%.o: %.s
	$(CC) $(ASMFLAGS) -o $@ -c $<

CCOMPILEDFILES=$(SOURCES:.c=.S) $(SOURCES:.c=.d) $(OBJECTS)

clean:
	rm -f $(APP).bin $(APP).hex $(APP).elf $(APP).map $(CCOMPILEDFILES)
