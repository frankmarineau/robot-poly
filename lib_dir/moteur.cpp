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

  TCCR0A =(1 << WGM00)| (1 << WGM01) | (1<<COM0A1)|(1<<COM0B1);     //Activiation du mode CTC
  TCCR0B = 0b101 ;                   // Activation du prescaler  1024
  OCR0A = dureeA; OCR0B = dureeB;  //Affectation des differentes vitesse
  PORTB &=0b11011011;              //Mise a zero des valeur de la direction
  PORTB |=direction;               //Affectation des nouvelle valeur de la direction 

}

