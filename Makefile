## Set Mcu Type
DEVICE=hc32f005

## A directory for common include files
BSP = bsp

## Get program name from enclosing directory name
APP = objects/$(lastword $(subst /, ,$(CURDIR)))

SOURCES=$(wildcard src/*.c) $(wildcard bsp/*.c)
OBJECTS=$(SOURCES:.c=.o) startup/startup_$(DEVICE).o

HEADERS=$(wildcard src/inc/*.h $(BSP)/inc/*.h)

CROSS ?= /Developer/gcc-arm-none-eabi/bin/arm-none-eabi-
AR = $(CROSS)ar
CC = $(CROSS)gcc
OBJCOPY = $(CROSS)objcopy

APPFLAGS = -I$(BSP)/inc -Isrc/inc
CFLAGS += -mthumb -mcpu=cortex-m0 -Os -Wall -MD
CFLAGS += -ffunction-sections -fdata-sections -fno-exceptions
CFLAGS += -DUSE_STDPERIPH_DRIVER

LDFLAGS += -mthumb -mcpu=cortex-m0 -Wl,-cref -Wl,--gc-sections
LDFLAGS += -T hc32_flash.ld
LDFLAGS += -Wl,-Map=$(APP).map

.PHONY: all clean

all: $(APP).bin $(APP).hex
$(APP).bin $(APP).hex: $(APP).elf

%.bin: %.elf
	$(OBJCOPY) -S -O binary $< $@

%.hex: %.elf
	$(OBJCOPY) -S -O ihex $< $@

$(APP).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(APPFLAGS) -c -o $@ $<

%.o: %.s
	$(CC) $(CFLAGS) -o $@ -c $<

CCOMPILEDFILES=$(SOURCES:.c=.asm) $(SOURCES:.c=.o) \
               $(SOURCES:.c=.d) $(SOURCES:.c=.sym)
clean:
	rm -f $(APP).bin $(APP).hex $(APP).elf $(APP).map $(CCOMPILEDFILES)
