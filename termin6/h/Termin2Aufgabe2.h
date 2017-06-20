// Headerfile für Termin2

#ifndef Termin2
#define Termin2

// Register von PIOB
#define PIOB_PER		((volatile unsigned int *) 0xFFFF0000)
#define PIOB_OER		((volatile unsigned int *) 0xFFFF0010)
#define PIOB_SODR 	((volatile unsigned int *) 0xFFFF0030)
#define PIOB_CODR 	((volatile unsigned int *) 0xFFFF0034)
#define PIOB_PDSR		((volatile unsigned int *) 0xFFFF003C)

// Leuchtdioden des AT91EB63
#define LED1	0x0100		// PIOB8
#define LED2	0x0200		// PIOB9
#define LED3	0x0400		// PIOB10
#define LED4	0x0800		// PIOB11
#define LED5	0x1000		// PIOB12
#define LED6	0x2000		// PIOB13
#define LED7	0x4000		// PIOB14
#define LED8	0x8000		// PIOB15
// Taster SW1-3 an PIOB des AT91EB63
#define SW1		0x08		// PIOB3
#define SW2		0x10		// PIOB4
#define SW3		0x20		// PIOB5
// Taster SW4 an PIOA des AT91EB63
#define SW4		0x200		// PIOA9	


// Register vom PMC
#define PMC_SCER		((volatile unsigned int *) 0xFFFF4000)
#define PMC_SCDR		((volatile unsigned int *) 0xFFFF4004)
#define PMC_SCSR		((volatile unsigned int *) 0xFFFF4008)
#define PMC_PCER		((volatile unsigned int *) 0xFFFF4010)
#define PMC_PCDR		((volatile unsigned int *) 0xFFFF4014)
#define PMC_PCSR		((volatile unsigned int *) 0xFFFF4018)

#endif // Termin2
