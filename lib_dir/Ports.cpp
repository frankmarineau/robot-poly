#include "Ports.h"

void Ports::initialiserPorts(volatile uint8_t *a,volatile uint8_t *b,volatile  uint8_t *c,volatile uint8_t *d) {
	*a = 0x00; // Capteur de ligne et photoresistances (entrées)
	*b= 0xfc; // Buzzer et sonar (sortie)
	//DDRC = 0xff; // LCD (sortie)
	*d = 0xf3; // Boutons (entrée) et moteurs (sortie)
}

uint8_t Ports::lireSonar() {
	return PINB0;
}

/*
uint8_t Ports::lirePhotoresistanceGauche() {
	return this.capteur.lecture(0) >> 2;
}

uint8_t Ports::lirePhotoresistanceDroite() {
	return this.capteur.lecture(1) >> 2;
}
*/

uint8_t Ports::lireCapteur() {
	return (PINA7 << 5) | (PINA6 << 4) | (PINA5 << 3) | (PINA4 << 2) | (PINA3 << 1) | PINA2;
}

// Cette fonction ne sera pas utiliser , car nous utilisons les interruptions directement pour le faire
uint8_t Ports::lireBoutonSelection() {
	return PIND0;
}

// Cette fonction ne sera pas utiliser , car nous utilisons les interruptions directement pour le faire
uint8_t Ports::lireBoutonConfirmation() {
	return PIND1;
}

void Ports::setDirectionMoteur(uint8_t val) {
	PORTD &= 0b00111111;
	PORTD |= val << 6;
}


// Nous n'aurons pas besoin de cette fonction, car le sont est regenerer par pwm, donc nous avons rien a mofidier a la valeur  qui est communiquer au port
 
void Ports::setSon(uint8_t val) {
	PORTB &= 0b11110011;
	PORTB |= val << 2;
}

void Ports::setSonar(uint8_t val) {
	PORTD &= 0b11111100;
	PORTD |= val;
}
