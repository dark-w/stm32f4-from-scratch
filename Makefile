all: blink

blink: main.c
	arm-none-eabi-gcc -mthumb -O0 -Wall -Werror -g -c main.c
	arm-none-eabi-ld -T ldscript.ld -o output.elf main.o
	arm-none-eabi-objdump -S output.elf
	arm-none-eabi-objcopy -O binary output.elf output.bin

flash: blink
	sudo st-flash write output.bin 0x20000000
	sudo st-flash reset

clean:
	rm -vf main.o output.elf output.bin
