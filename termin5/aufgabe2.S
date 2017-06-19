// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe2.S"
	.text			@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2		@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
				@ unteren 2 Bit sind 0
	.global	main		@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:

	push	{lr}
	
        mov r0, #0
	mov r1, #1
	mov r2, #1
	mov r3, #1

	bl	up1
	

    
	bl	up2
	bl	up3
	

// UP1 benutzt nur Scratchregister und stellt keine Blattroutine dar (ruft somit weitere
// Unterprogramme auf)	
up1:
    
    bl up2
    
     MOV PC, LR 
    
// UP2 benutzt nur Scratchregister und stellt eine Blattroutine dar (ruft somit keine weiteren
// Unterprogramme auf)
up2: @summiert 4 parameter auf

    add r0, r1
    add r0, r2
    add r0, r3

     MOV PC, LR 
//UP3 benutzt Nicht-Scratchregister und stellt keine Blattroutine dar
up3:

    stmfd 	sp!, {r4, r5, r6, r7, r8, r9, r10, r11}
    mov r10, #0
    ldmfd	sp!, {r4, r5, r6, r7, r8, r9, r10, r11}

fertig:

	pop	{pc}
.Lfe1:
	.size	main,.Lfe1-main
// End of File
