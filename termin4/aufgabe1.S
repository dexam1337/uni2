// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe1.S"
	.text			@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2		@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
				@ unteren 2 Bit sind 0
	.global	main		@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
//	Hier bitte Ihren ProgrammCode einfuegen
	
	mov 	r0, #0
	str 	r1, [r0], #4 	// speichert 0x1ffff8 aus r1 auf Adresse 0x0 danach steht in r0 0x4
	mov 	r0, #0
	str 	r1, [r0, #4] 	// speichert aus r1 auf Adresse 0x0 plus ein offset von 4 danach steht in r0 0x0
	mov 	r0, #0
	str 	r1, [r0]! 	// auf Adresse 0x0 danach steht in r0 0x0
	mov 	r0, #0
	str 	r1, [r0, #4]! 	// auf Adresse 0x0 danach steht in r0 0x4
	mov 	r0, #0
	strb 	r1, [r0, #1]! 	// auf Adresse 0x0 danach steht in r0 0x1
	mov 	r1, #4
	strb 	r1, [r0, r1]! 	// speichert r1 auf Adresse 0x1 danach steht in r0 0x5 weil 0x1 aus r0 + 0x4 aus r1 in unser adressregister speichert werden.
	
	bx	lr
.Lfe1:
	.size	main,.Lfe1-main

// End of File
