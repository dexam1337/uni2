// Programmgeruest zur Aufgabe Termin6 WS2013
// von: Manfred Pester
// vom: 18.09.2013
// @ int Operationen(volatile unsigned int* u_int_Taster, volatile unsigned int* u_int_LedsOn) 
@ Diese Funktion soll auf 
@ - LED DS1 (Bit 8) das Ergebnis von SW1 AND SW2 anzeigen 
@ - LED DS2 (Bit 9) das Ergebnis von SW1 OR SW2 anzeigen 
@ - LED DS3 (Bit 10) das Ergebnis von SW1 EOR SW2 anzeigen 
@ - LED DS4 und 5 (Bit 11/12) das Ergebnis von SW1 ADD SW2 anzeigen 
@ - LED DS6 und 7 (Bit 13/14) das Ergebnis von SW1 SUB SW2 anzeigen 
@ und bei gedrueckter TASTE SW3 (Bit 5) soll die Funktion ein TRUE (Wert ungleich 0) ansonsten FALSE (Wert gleich 0) an das aufrufende Programm zurueck geben.
@ ACHTUNG die Tasten und auch die Leuchtdioden sind Low-Aktiv beschaltet.
	.file	"Funktionen.S" 
	.text 
	.align	2 
	.global	Operationen 
	.type	Operationen, %function 
Operationen: 
        PUSH {r4, r5}
	 
	 LDR r2, [r0] //lade werte der schalter
	 EOR r2, r2, #0x38 //negieren wie aus "Hilfe" vorgegeben
	 MOV r3, r2 //kopiere
	 MOV r4, r2
	 
	 LSR r2, r2, #3 //Unterster bit ist jetzt taster 1
	 LSR r3, r3, #4 //fuer taster 2
	 LSR r4, r4, #5 //fuer taster 3
	 
	 AND r2, r2, #1   //isoliere letzes bit
	 AND r3, r3, #1  //isoliere letzes bit
	 AND r4, r4, #1 //isoliere letzes bit
	 
	 
// AND	 
    
        AND r5, r2, r3 // compare SW1 und SW2
        LSL r5, #8 //shifte um eins nach links
        STR r5, [r1]

// OR	 

        ORR r5, r2, r3
        LSL r5, #9
        STR r5, [r1]

// EOR 

        EOR r5, r2, r3
        LSL r5, #10
        STR r5, [r1]

// ADDITION	 
        
        ADD r5, r2, r3
        LSL r5, #11
        STR r5, [r1]

// SUBTRAKTION 
        
        SUB r5, r2, r3 //Sicherlich falsch wenn r2 = 0, r3 = 1 dann irgendwas 0xffff
        LSL r5, #13
        AND r5, r5, #0x6000
        STR r5, [r1]
	 
// Beenden 

    mov r0, r4 //wenn taste 3 gedr?ckt war wird beim verlassen der schleife geloescht
    pop {r4, r5}
    bx lr
 
.Lfe1: 
	.size	Operationen,.Lfe1- Operationen 
// End of File
