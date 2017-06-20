build:
	arm-elf-gcc -c -g termin6.c -o termin6.o
	arm-elf-gcc -c -g Funktionen.S -o Funktionen.o
	arm-elf-gcc -c -g ./boot/boot_ice.S -o boot.o
	arm-elf-gcc -c -g ./boot/swi.S -o swi.o

	
	arm-elf-ld -Ttext 0x2000000 termin6.o Funktionen.o boot.o swi.o  -o term6.elf
