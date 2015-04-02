#include "Ports.h"

Ports::initialiserPorts(){

}

uint8_t Ports::lireSonar(){
	return PINB0;
}

uint8_t Ports::lirePhotoresistanceGauche(){
	return (PINA1 << 1) | PINA0;
	// TODO: Lire avec can
}

uint8_t Ports::lirePhotoresistanceDroite(){
	return (PINA1 << 1) | PINA0;
	// TODO: Lire avec can
}

uint8_t Ports::lireCapteur(){
	return (PINA7 << 5) | (PINA6 << 4) | (PINA5 << 3) | (PINA4 << 2) | (PINA3 << 1) | PINA2;
}

uint8_t Ports::lireBoutonSelection(){
	return PIND0;
}

uint8_t Ports::lireBoutonConfirmation(){
	return PIND1;
}

void Ports::setDirectionMoteur(uint8_t val){
	PORTD &= 0b11110011;
	PORTD |= val << 2;
}

void Ports::setDirectionMoteur(uint8_t val){
	PORTD &= 0b11110011;
	PORTD |= val << 2;
}