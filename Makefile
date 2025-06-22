all: blink

blink: main.c
	arm-none-eabi-gcc -mthumb -O0 -Wall -Werror -g -c main.c startup.c
	arm-none-eabi-ld -M -T ldscript.ld -o output.elf main.o startup.o
	arm-none-eabi-objdump -S output.elf
	arm-none-eabi-objcopy -O binary output.elf output.bin

flash: blink
	sudo st-flash write output.bin 0x8000000
	sudo st-flash reset

clean:
	rm -vf *.o output.elf output.bin

debug:
	# openocd -f interface/stlink.cfg -f board/stm32f4discovery.cfg
	gdb-multiarch output.elf -ex "target extended-remote localhost:3333"
