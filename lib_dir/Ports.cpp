#include "Ports.h"

Ports::initialiserPorts() {
	DDRA = 0x00; // Capteur de ligne et photoresistances (entrées)
	DDRB = 0xff; // Buzzer et sonar (sortie)
	DDRC = 0xff; // LCD (sortie)
	DDRD = 0b11000000; // Boutons (entrée) et moteurs (sortie)
}

uint8_t Ports::lireSonar() {
	return PINB0;
}

uint8_t Ports::lirePhotoresistanceGauche() {
	return this.capteur.lecture(0) >> 2;
}

uint8_t Ports::lirePhotoresistanceDroite() {
	return this.capteur.lecture(1) >> 2;
}

uint8_t Ports::lireCapteur() {
	return (PINA7 << 5) | (PINA6 << 4) | (PINA5 << 3) | (PINA4 << 2) | (PINA3 << 1) | PINA2;
}

uint8_t Ports::lireBoutonSelection() {
	return PIND0;
}

uint8_t Ports::lireBoutonConfirmation() {
	return PIND1;
}

void Ports::setDirectionMoteur(uint8_t val) {
	PORTD &= 0b11110011;
	PORTD |= val << 2;
}

void Ports::setSon(uint8_t val) {
	PORTB &= 0b11110011;
	PORTB |= val << 2;
}

void Ports::setSonar(uint8_t val) {
	PORTD &= 0b11111100;
	PORTD |= val;
}