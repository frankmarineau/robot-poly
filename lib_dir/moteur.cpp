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
	ajustementTimer2(vitesseA, vitesseB, 0x00);
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
	ajustementTimer2(vitesseA, vitesseB, 0x03);
}

void Moteur::tournerDroite(uint8_t vitesse) {
	ajustementTimer2(vitesse,vitesse,0x02); //Droite
}

void Moteur::tournerGauche(uint8_t vitesse) {
	ajustementTimer2(vitesse,vitesse,0x01); //Gauche
}

void Moteur::arreter() {
	ajustementTimer2(0,0,0x00);
}

void Moteur::ajustementTimer2(uint8_t vitesseA, uint8_t vitesseB, uint8_t direction)
{
	TCCR2A = (1 << WGM22)| (1 << WGM20) | (1 << COM2A1)|(1 << COM2B1)  ;
	TCCR2B = (1<< CS22) | (1<< CS21) | (1<< CS20) ;
	OCR2A = vitesseA ; OCR2B = vitesseB;
	PORTD &= 0xCF; //Reinitialiser la direction
 	PORTD |= direction << 4; //Nouvelle direction
}

