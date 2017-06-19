// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe3.S"
	.text			@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2		@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
				@ unteren 2 Bit sind 0
	.global	main		@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:

Loop:	   LDA 	Total	; Accumulate total
Add_instr: ADD Table	; Begin at head of table
	   STO Total	;
	   LDA Add_instr; Change address ...
	   ADD One	; by modifying instruction!
	   STO Add_instr;
	   LDA Count	; Count iterations
	   SUB One	; Count down to zero
	   STO Count	;
	   JGE Loop	; If >= 0 repeat
	   STP		; Halt execution

; Data definitions
Total	DEFW 0 	; Total - initially zero
One	DEFW 1 	; The number one
Count	DEFW 4 	; Loop counter (loop 5x)
Table	DEFW 39 ; The numbers to total ...
	DEFW 25 ;
	DEFW 4 	;
	DEFW 98 ;
	DEFW 17 ;

Halt:
	b	Halt

//; Data definitions
//Total 	DEFW 0 ; Total - initially zero
Total:	.word	0
//One 	DEFW 1 ; The number one
//Count 	DEFW 4 ; Loop counter (loop 5x)
Count:	.word	4
//Table 	DEFW 39 ; The numbers to total ...
//	DEFW 25 ;
//	DEFW 4 ;
//	DEFW 98 ;
//	DEFW 17 ;
Table:	.word	39, 25, 4, 98, 17


.Lfe1:
	.size	main,.Lfe1-main

// End of File
