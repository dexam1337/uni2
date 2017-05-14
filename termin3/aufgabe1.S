// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe1.S"
	.text		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
			@ unteren 2 Bit sind 0
	.global	main	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
	MOV R0, R1, LSR #2	@ Kopiert R1 in R0 mit einem logical Rigth shift
	ADD R0, R1, R1, LSL #3	@ Addiert R1 mit R1 in R0 mit einem logical shift left

	bx	lr	@ Ruecksprung zum aufrufenden Programm
.Lfe1:
	.size	main,.Lfe1-main	@ Programmgroesse berechnen

// End of File
