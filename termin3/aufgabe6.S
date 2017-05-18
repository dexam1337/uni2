// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe6.S"
	.text		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
			@ unteren 2 Bit sind 0
	.global	main	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
	LDR	r0, Beispiel
	
//EOR r0, #0xFFFF0000
//Eventuell 4mal nach rechts in register 
//4 mal nach links in register
//dann byteweise zusammenführen?

	bx	lr
Beispiel:
	.word	0x1234ABCD
.Lfe1:
	.size	main,.Lfe1-main

// End of File
