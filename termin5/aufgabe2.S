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

	bl	up1
	bl	up2
	bl	up3
	
	pop	{pc}

// UP1 benutzt nur Scratchregister und stellt keine Blattroutine dar (ruft somit weitere
// Unterprogramme auf)	
up1:



// UP2 benutzt nur Scratchregister und stellt eine Blattroutine dar (ruft somit keine weiteren
// Unterprogramme auf)
up2:
   
fiboiter:

@zaehler liegt in r0
  mov r1, #0 @a
  mov r2, #1 @b
    fiboiterloop:
      add r3, r1, r2 @neu = a + b
      mov r1, r2 @ a = b
      mov r2, r3 @ b = neu
      subs r0, #1 @zaehler um 1 reduzieren und flags updaten.
      bne fiboiterloop @ falls zaehler != 0 nochmal
    mov r0, r3 @ergebnis auf r0 zur rückgabe schieben.
  


//UP3 benutzt Nicht-Scratchregister und stellt keine Blattroutine dar
up3:



.Lfe1:
	.size	main,.Lfe1-main

// End of File
