// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe2.S"
	.text			@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2		@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
				@ unteren 2 Bit sind 0
	.global	main		@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
	
	stmfd sp!, {r4, r5, lr} @ Ruecksprungadresse und Register sichern
main:
    @mov r2, #0x9000013
    adr r1, marke
    
    @msr cpsr, #128
    @msr cpsr, r2
marke: 
    mov r0, #0

end:
    bne marke

fertig:
    ldmfd sp!, {r4, r5, pc} @ Ruecksprungadresse und RegisterF
.Lfe1:
	.size	main,.Lfe1-main
	

// End of File
