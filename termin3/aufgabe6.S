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
	

  AND r1, r0, #0xff000000
  AND r2, r0, #0xff00
  LSR r1, r1,  #8
  LSR r2, r2, #8
  ORR r3, r2, r1
  AND r1, r0, #0x00ff0000
  AND r2, r0, #0xff
  LSL r1, r1, #8
  LSL r2, r2, #8
  ORR r4, r2, r1
  ORR r5, r4, r3
  
	bx	lr
Beispiel:
	.word	0x1234ABCD
.Lfe1:
	.size	main,.Lfe1-main

// End of File
