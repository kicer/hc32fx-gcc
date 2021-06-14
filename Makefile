## Set Mcu Type
DEVICE=hc32f003x4
MCPU=cortex-m0

TOOLCHAIN ?= /Developer/gcc-arm-none-eabi
FLASHTOOL ?= /Developer/hc32flash
SERIAL ?= /dev/tty.SLAB_USBtoUART

## A directory for common include files
BSP = bsp

## Get program name from enclosing directory name
APP = objects/$(lastword $(subst /, ,$(CURDIR)))

SOURCES  = $(wildcard src/*.c) $(wildcard bsp/*.c)
OBJECTS  = $(SOURCES:.c=.o)
OBJECTS += startup/core.o
OBJECTS += startup/$(DEVICE)_vt.o

HEADERS=$(wildcard src/inc/*.h $(BSP)/inc/*.h)

CC = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
AS = $(TOOLCHAIN)/bin/arm-none-eabi-as
LD = $(TOOLCHAIN)/bin/arm-none-eabi-ld
OC = $(TOOLCHAIN)/bin/arm-none-eabi-objcopy
OD = $(TOOLCHAIN)/bin/arm-none-eabi-objdump
OS = $(TOOLCHAIN)/bin/arm-none-eabi-size

APPFLAGS = -I$(BSP)/inc -Isrc/inc

ASMFLAGS += -O0 -mcpu=$(MCPU) -mthumb -Wall
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
LDFLAGS += -lgcc -nostdlib --specs=nosys.specs


.PHONY: all clean serial

all: $(APP).hex $(APP).bin
$(APP).bin $(APP).hex: $(APP).elf

%.bin: %.elf
	$(OC) -S -O binary $< $@
	$(OS) $<

%.hex: %.elf
	$(OC) -S -O ihex $< $@

$(APP).elf: $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(APPFLAGS) -o $@ $<

%.o: %.S
	$(CC) -c $(ASMFLAGS) -o $@ $<

%.o: %.s
	$(CC) -c $(ASMFLAGS) -o $@ $<

CCOMPILEDFILES=$(SOURCES:.c=.S) $(SOURCES:.c=.d) $(OBJECTS)

clean:
	rm -f $(APP).bin $(APP).hex $(APP).elf $(APP).map $(CCOMPILEDFILES)

serial:
	$(FLASHTOOL)/hc32flash.py -d $(DEVICE) -p $(SERIAL) -u -w $(APP).bin -b 115200 -R
