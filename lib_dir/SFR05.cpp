//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE ++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015  //
// Ecrit par : Foromo Daniel Soromou                                                              //
//             Hermann Charbel Racine Codo                                                        //
//             Esteban Sanchez                                                                    //
//             Francis Marineau                                                                   //
// Ecrit le Mardi 14 Avril 2015                                                                   //
// Description : Ce fichier d'entete, fixe l'ensemble des fichiers d'entete necessaire pour la    //
//               la realisation du projet. En plus, il fixe aussi les entrees/sorties pour les    //
//               differents composants utilises et autres constantes.                             //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#include "SFR05.h"


Sonar::Sonar()
{
	//DDRD = 0b11111101;			// Port B pin 0 ouput all others input  
	TCCR1A = 0x04;			// Set timer up in CTC mode
	TCCR1B = 0x08;		
}


unsigned int Sonar::getEcho(void)
{
	unsigned int range;
 
	while(!(PINB&0x02));	  // Wait for echo pin to go high,  this indicates the start of the incoming pulse
	TCNT1 = 0x00; 		 // Clear timer to zero
	TCCR1B = START_CLK_N;	// Start timer running 1:8 prescaler in normal mod
	while((PINB&0x02));	// Wait for echo pin to go low signaling that the pulse has ended
	
	TCCR1B = STOP_CLK;	// Stop the timer and set back to CTC mode	
	range = TCNT1/148;	// Read back value in the timer counter register, this number divided by 58 will give us the range in CM	
	return(range);
}

void Sonar::startTimer(unsigned int time)
{
	OCR1A = time;			// Time set to count to
	TIFR1 = 0x02;			// Clear timer campare match flag
	TCNT1 = 0x00; 			// Clear timer to zero
	TCCR1B = START_CLK;		// Start timer running 1:8 prescaler
}

void Sonar::waitForTimer(void)
{
	while(!(TIFR1&0x02));	// wait for timer to set compare match flag
	TCCR1B = STOP_CLK;		// Stop the timer
}



void Sonar::startRange(void)
{
	PORTB &=0b11111110;
	PORTB |= 0b00000001;		// Send trigger pin high	
	startTimer(0x0001);			// Wait around 10uS before sending it low again	
	waitForTimer();	
	PORTB &=0b11111110;		
}



