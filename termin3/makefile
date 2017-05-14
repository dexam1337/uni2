# makefile für Rechnerarchitekturpraktikum Termin 3 SS2013
# von: Manfred Pester
# vom: 12.02.2013

# Variable fuer den zu nutzenden Compiler
GCC = arm-elf-gcc

all: aufgabe1 aufgabe2 aufgabe3 aufgabe5 aufgabe6

aufgabe1: aufgabe1.S
	$(GCC) -g aufgabe1.S -o aufgabe1.elf

aufgabe2: aufgabe2.S
	$(GCC) -g aufgabe2.S -o aufgabe2.elf
	
aufgabe3: aufgabe3.S
	$(GCC) -g aufgabe3.S -o aufgabe2.elf

aufgabe5: aufgabe5.S
	$(GCC) -g aufgabe5.S -o aufgabe5.elf

aufgabe6: aufgabe6.S
	$(GCC) -g  aufgabe6.S -o aufgabe6.elf

zusatzaufgabe: zusatzaufgabe.S 
	$(GCC) -g  zusatzaufgabe.S -o zusatzaufgabe.elf

clean:
	rm *.o
	rm *.elf			
