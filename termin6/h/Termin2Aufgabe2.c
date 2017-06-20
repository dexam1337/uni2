// Lösung zu Termin2
// Aufgabe 1
// von: Manfred Pester
// vom: 27.07.2003
// 

#define PIOB_PER		((volatile unsigned int *) 0xFFFF0000)
#define PIOB_OER		((volatile unsigned int *) 0xFFFF0010)
#define PIOB_SODR 	((volatile unsigned int *) 0xFFFF0030)
#define PIOB_CODR 	((volatile unsigned int *) 0xFFFF0034)

#define PMC_SCER		((volatile unsigned int *) 0xFFFF4000)
#define PMC_SCDR		((volatile unsigned int *) 0xFFFF4004)
#define PMC_SCSR		((volatile unsigned int *) 0xFFFF4008)
#define PMC_PCER		((volatile unsigned int *) 0xFFFF4010)
#define PMC_PCDR		((volatile unsigned int *) 0xFFFF4014)
#define PMC_PCSR		((volatile unsigned int *) 0xFFFF4018)


int main(void)
{

	*PMC_PCER		= 0x4000;	// Peripheral Clock für PIOB einschalten
			
	*PIOB_PER		= 0x0100;	// Enable Register 8 LED's und Taster an PB3
	*PIOB_OER		= 0x0100;	// Output Enable Register 8 LED's sind aus
	
	while(1)
	{
		*PIOB_SODR 	= 0x0100;	// Set Output Data Register LED's sind aus
		*PIOB_CODR 	= 0x0100;	// Clear Output Data Register LED's leuchten
	}
	
	return 0;
}
