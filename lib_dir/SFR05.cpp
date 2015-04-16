//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Detection d'obstacle, ainsi la distance a la quelle l'obstacle est placee                //
//                                                                                                        //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#include "SFR05.h"                                         //Fichier d'entete necessaire                  //
//++++++++++++++++++++++++++++++++++++++++++ Sonar::Sonar() ++++++++++++++++++++++++++++++++++++++++++++++//
// Description     : (Constructeur), Fixer les registres du timer/Counter1 utiliser                       //
// Type de methode : Privee                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
Sonar::Sonar()                                         //Entete de la fonction                            //
{                                                                                                         //
	TCCR1A = 0x04;	//(1 << WGM12)                 Acivation u mode CTC                               //
	TCCR1B = 0x08;	//(1 << CS12) | (1<<CS11) | (1<< CS10) Prescaler 1024                             //	
}                                                                                                         //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//+++++++++++++++++++++++++++++++++++ Sonar::receivePulse(void) ++++++++++++++++++++++++++++++++++++++++++//
// Description     : Calcul de la distance d'un obstacle en pouce                                         //
// Type de methode : Public                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: uint16_t range; Distance de l'osbtacle                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
uint16_t Sonar::receivePulse(void)                            //Entete de la fonction                     //
{                                                                                                         //
	uint16_t range;                                  //Distance de l'obstacle                         //
	while(!(PINB&0x02));	                         //Attendre l'envoie de l'onde                    //
	TCNT1 = 0x00; 		                         //Mise a zero du compteur                        //
	TCCR1B = START_CLK_N;	                         //Fixer un prescaler de 1024                     //
	while((PINB&0x02));	                         //Attendre la reception de l'onde                //
	TCCR1B = STOP_CLK;	                         //Arreter le timer                               //
	range = TCNT1/148;	                         //Calcul de distance de l'obstacle en pouce      //	
	return(range);                                   //Retour du resultat                             //
}                                                                                                         //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//++++++++++++++++++++++++++++++++++++++++++ Sonar::Sonar() ++++++++++++++++++++++++++++++++++++++++++++++//
// Description     : Demarrer un timer pour un interval de temps donner                                   //
// Type de methode : Public                                                                               //
// Parametre(s)    : uint16_t timer, le delay du timer                                                    //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Sonar::startTimer(uint16_t time)                                                                     //
{                                                                                                         //
	OCR1A = time;			                //Fixer le temps du timer                         //
	TIFR1 = 0x02;			                //Mise a 0 du flag de comparaison                 //
	TCNT1 = 0x00; 			                //Mise a 0 du counter1                            //
	TCCR1B = START_CLK;		                //Demarrer le timer , avec prescaler 1024         //
}                                                                                                         //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//+++++++++++++++++++++++++++++++++++ Sonar::waitForTimer(void) ++++++++++++++++++++++++++++++++++++++++++//
// Description     : Attendre l'ecoulement du timer                                                       //
// Type de methode : Public                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Sonar::waitForTimer(void)                         //Entete de la fonction                            //
{                                                                                                         //
	while(!(TIFR1&0x02));	                       //Attendre que le flag soit a 1, OCR1A = time      //
	TCCR1B = STOP_CLK;		               //Arreter le timer                                 //
}                                                                                                         //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//+++++++++++++++++++++++++++++++++++++++ Sonar::sendPulse() +++++++++++++++++++++++++++++++++++++++++++++//
// Description     : Envoie d'une onde sur une periode de 10uS                                            //
// Type de methode : Public                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Sonar::sendPulse(void)                            //Entete de la fonction                            //
{                                                                                                         //
	PORTB &=0b11111110;                            //Mise a 0 de la premiere pin du port B            //
	PORTB |= 0b00000001;		               //Mise a 1 de la premiere pin du port B            //	
	startTimer(0x0001);			       //Lancer un timer de 10uS                          //
	waitForTimer();	                               //Attendre l'ecoulement de la muniterie            //
	PORTB &=0b11111110;		               //Mise a 0 de la premiere pin du port B            //
}                                                                                                         //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


