// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe2.S"
	.text		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
			@ unteren 2 Bit sind 0
	.global	main	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
	MOV	r0, #1
	MOV	R1, #0x80000000
        MOV     R2, #0xffffffff
        
	ADDS	r3, r0, r1	@ setzt nur das Vorzeichenflag
	ADDS r4, r0, r2 @ 0x1 + 0xffffffff carry und zero flag
	ADDS r5, r2, r2 @ overflow
        SUBS r6, r0, r0 @ 0x1-0x1 sollte 0 ergeben Z-flag
        SUBS r7, r0, r1 @ 0x1 - 0x80000000 sollte negativ sein N flag

	bx	lr
.Lfe1:
	.size	main,.Lfe1-main

// End of File
