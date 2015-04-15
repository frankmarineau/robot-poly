#include "moteur.h"

Moteur::Moteur(uint8_t vitesse) : VITESSE(vitesse) {

}

void Moteur::avancer(uint8_t direction) {
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
	ajustementTimer1(vitesseA, vitesseB, 0x00);
}

void Moteur::reculer(uint8_t direction) {
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
	ajustementTimer1(vitesseA, vitesseB, 0x03);
}

void Moteur::tournerDroite(uint8_t vitesse) {
	ajustementTimer1(vitesse,vitesse,0x02); //Droite
}

void Moteur::tournerGauche(uint8_t vitesse) {
	ajustementTimer1(vitesse,vitesse,0x01); //Gauche
}

void Moteur::arreter() {
	ajustementTimer1(0,0,0x00);
}

void Moteur::ajustementTimer1( uint8_t dureeA, uint8_t dureeB, uint8_t direction)
{
  TCCR1A |= (1 << WGM10) | (1 << COM1A1)|(1 << COM1B1) ;
  TCCR1B |= (1<< CS11) ;
  OCR1A = dureeA ; OCR1B = dureeB;

  PORTD &= 0x3F; //Reinitialiser la direction
  PORTD |= direction << 6; //Nouvelle direction

}

