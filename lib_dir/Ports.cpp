#include "Ports.h"

void Ports::initialiserPorts(volatile uint8_t *a,volatile uint8_t *b,volatile  uint8_t *c,volatile uint8_t *d) {
	*a = DDRA_VALUE; // Capteur de ligne et photoresistances (entrées)
	*b = DDRB_VALUE; // Buzzer et sonar (sortie)
	//DDRC = 0xff; // LCD (sortie)
	//*d = DDRD_VALUE; // Boutons (entrée) et moteurs (sortie)
}

uint8_t Ports::lireSonar() {
	return PINB0;
}

uint8_t Ports::lirePhotoresistanceGauche() {
	can capteur;
	return capteur.lecture(6) >> 2;
}

uint8_t Ports::lirePhotoresistanceDroite() {
	can capteur;
	return capteur.lecture(7) >> 2;
}





