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
	stmfd 	sp!, {r6, r9, lr}
	ldr	r9, =0x8000
	
	ldmda	r9, {r1, r2, r6} @laed aus dem speicher unter der adresse r9 mehrere in r6,r2,r1 und decrementiert die adresse nach jedem ladeschritt // reihenfolge in registern ist equivalent zu dem im speicher wenn adresse aufsteigend ware
	ldmfd	r9, {r1, r2, r6} @laed aus dem speicher unter der adresse r9 in r1, r2, r6 und incrementiert die adresse nach jedem schritt //reihenfolge in register equivalent zu den im speicher

	ldmfd	sp!, {r6, r9, pc}
.Lfe1:
	.size	main,.Lfe1-main

// End of File
