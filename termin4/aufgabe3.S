// Loesung Aufgabe 3 und 4 von Termin4 Rechnerarchitektur SS2013
// Name: 	Matrikelnummer:
// Name: 	Matrikelnummer:
// Datum:
	.file "aufgabe3.S"
	.text 		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align 2 	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen	
			@ unteren 2 Bit sind 0
	.global main 	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type main,function
main:
	stmfd sp!, {r4, r5, lr} @ Ruecksprungadresse und Register sichern
kopieren:
@ hier Ihr Programm zum Kopieren einer Byte-Tabelle (je 8Bit) in eine Word-Tabelle (je 32Bit) einfuegen
    LDR r1, =Liste1 @ r1 zeigt auf Liste1
    LDR r2, =Liste2 @ r2 zeigt auf Liste2
    LDRB r3, [r1] @anzahl der elemente holen
schleife:

    LDRSB r0, [r1] @ lade ersten Wert
    @konvertieren in 32-bit durcg LDRSB
    
    STR r0,[r2] @ speichere ihn in Liste2
    ADD r1, #1 @ Lesezeiger verschieben
    ADD r2, #4 @ Schreibzeiger verschieben
    SUBS r3, #1 @runterzaehlen und flags updaten
    bne schleife
    	
sortieren:
@ hier Ihr Programm um die vorzeichenrichtige Zahlen in Liste2 zu sortieren
   LDR r2, = Liste2 @Liste 2 pointer holen
   LDR r3, [r2] @Anzahl der elemente holen
   SUB r3, #1
   ADD r2, #4 @Increment
   
check: @ueberpruefung ob r0 < r1 ist
   LDR r0, [r2]
   LDR r1, [r2, #4]
   CMP r0, r1
   bmi tauschen
   bal nicht_tauschen


   
tauschen:
   @SUB r2, #4 @zum vorherigen register
   STR r1, [r2] @den zweiten wert zuerst speichern
   @ADD r2, #4 @hochzaehlen
   STR r0, [r2, #4 ]! @den ersten wert danach speichern >> getauscht.
   SUBS r3, #1
   bne check
   
nicht_tauschen:
   @SUB r2, #4 @zum vorherigen register
   STR r0, [r2] @den ersten wert zuerst speichern
   @ADD r2, #4 @hochzaehlen
   STR r1, [r2, #4]! @den zweiten wert danach speichern >> nicht getauscht.
   SUBS r3, #1
   bne check
fertig:
	ldmfd sp!, {r4, r5, pc} @ Ruecksprungadresse und Register

TAB2: .word Liste2 @ Beispiel um an Adressen aus anderen Segmenten zu kommen

.Lfe1:
	.size main,.Lfe1-main

// .data-Section fuer initialisierte Daten
	.data
// Erster Wert der Tabelle steht fuer die Anzahl (max. 64) der Werte der Tabelle
Liste1: .byte (Liste1Ende-Liste1), -9, 8, -7, 6, -5, 4, -3, 2, -1, 0, 127, 128
Liste1Ende:

// .comm-Section fuer nicht initialisierte Daten
	.comm Liste2, ((Liste1Ende-Liste1)*4) 	@ Speicherbereich mit der Groesse*4 von Liste1 reservieren

// End of File

