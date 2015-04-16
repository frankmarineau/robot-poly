#include "moteur.h"

Moteur::Moteur(uint8_t vitesse) : VITESSE(vitesse) {

}

void Moteur::avancer(int8_t direction) {
	//Calculer vitesse de chaque roue
	uint8_t vitesseA = VITESSE;
	uint8_t vitesseB = VITESSE;
	if (direction >= 0) {
		vitesseB = round(VITESSE * (90 - direction) / 90);
	}
	else {
		vitesseA = round(VITESSE * (90 + direction) / 90);
	}

	//Ajuster PWM
	ajustementTimer1(vitesseA, vitesseB, DIRECTION_AVANCE);
}

void Moteur::reculer(int8_t direction) {
	//Calculer vitesse de chaque roue
	uint8_t vitesseA = VITESSE;
	uint8_t vitesseB = VITESSE;
	if (direction >= 0) {
		vitesseB = round(VITESSE * (90 - direction) / 90);
	}
	else {
		vitesseA = round(VITESSE * (90 + direction) / 90);
	}

	//Ajuster PWM
	ajustementTimer1(vitesseA, vitesseB, DIRECTION_ARRIERE);
}

void Moteur::tournerDroite(uint8_t vitesse) {
	ajustementTimer1(vitesse,vitesse,DIRECTION_DROITE); //Droite
}

void Moteur::tournerGauche(uint8_t vitesse) {
	ajustementTimer1(vitesse,vitesse,DIRECTION_GAUCHE); //Gauche
}

void Moteur::arreter() {
	ajustementTimer1(0,0,0x00);
}

void Moteur::ajustementTimer1( uint8_t dureeA, uint8_t dureeB, uint8_t direction)
{
 /* TCCR1A |= (1 << WGM10) | (1 << COM1A1)|(1 << COM1B1) ;
  TCCR1B |= (1<< CS11) ;
  OCR1A = dureeA ; OCR1B = dureeB;

  PORTD &= 0x3F; //Reinitialiser la direction
  PORTD |= direction << 6; //Nouvelle direction*/
  TCCR0A =(1 << WGM00)| (1 << WGM01) | (1<<COM0A1)|(1<<COM0B1);     // CTC mode, toggle OC0 on compare match
  TCCR0B = 0b101 ;                   // Start timer0 with prescaler 	
  OCR0A = dureeA; OCR0B = dureeB;
  PORTB &=0b11011011;
  PORTB |=direction;

}

