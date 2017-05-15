// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe3.S"
	.text		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
			@ unteren 2 Bit sind 0
	.global	main	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
	push	{r4, r5, r6, r7, r9, lr}

	ldr	R0, = 0xaabbccdd
	ldr	R1, = 0xffbbffbb
	ldr	R2, = 0xfffffffe
	ldr	r3, = 0x000b774d 	@ z.B. Matrikelnummer
	ldr	r4, = 0x3
	ldr	r5, = 0x2
	ldr	r6, = 0x7fffffff
	ldr	r7, = 0x80000000
				@ R9 (hexadez.) - 						N, Z, C, V
	ANDS	R9, R0, R3	@ 	0xaabbccdd - 0x000b774d = 0xaab05590 	- Wie werden die Flags N, Z, C, V gesetzt?	gar keine?
	EOR	R9, R3, R3	@ 	0	- Gilt das Ergebnis f??r jeden Wert in R3?	ja da ein XOR bei gleichen werten immer 0 ergibt
	SUBS	R9, R7, #3	@ 	0x80000000 - 0x30000000 = 0x7ffffffd 	- Wie werden die Flags N, Z, C, V gesetzt?	_, _, _, _
	RSBS	R9, R5, #3	@ 		- Wie werden die Flags N, Z, C, V gesetzt?	_, _, C, _ Reverse Subtract without carry.
	ADDS	R9, R4, #12	@ 		- Wie werden die Flags N, Z, C, V gesetzt?	n?scht
	ADDS	R9, R6, R4	@ 		- Wie werden die Flags N, Z, C, V gesetzt?	N, _, _,V
	TST	R4, #1		@ 		- Wie werden die Flags N, Z, C, V gesetzt?	_, _, _, _ Overflow ist vom ADD bestehen geblieben 
	TEQ	R4, R4		@ 		- Wie werden die Flags N, Z, C, V gesetzt?	_, _, _, _ XOR bei gleichen zahlen immer 0 deswegen zero flag, und Overflow aus ADD bestehen
	CMP	R5, R4		@ 		- Wie werden die Flags N, Z, C, V gesetzt?	_, _, _, _
	CMN	R2, R5		@ 		- Wie werden die Flags N, Z, C, V gesetzt?	_, _, _, _
	ORR	R9, R0, R3	@ 
	MOV	R9, #126	@ 126 in R9 speichern
	BIC	R9, R0, R1	@
	BIC	R9, R2, #15	@
	MVN	R9, R1		@

	pop	{r4, r5, r6, r7, r9, pc}
.Lfe1:
	.size	main,.Lfe1-main

// End of File
