#ifndef MOTEUR_H
#define MOTEUR_H

#include <avr/io.h>
#include "utility.h"

class Moteur {
public:
	Moteur(uint8_t vitesse = 100, uint8_t vitesseRotation = 100);

	// Avance dans une certaine direction - entre 0 et 90
	void avancer(uint8_t direction);
	// Recule dans une certaine direction - entre 90 et 180
	void reculer(uint8_t direction);
	// Tourne sur place d'un certain nombre de degrée - négatif si anti-horaire
	void tourner(uint8_t degree);
	//Arrete de bouger
	void arreter();

	//Ajuster le timer pour générer le pwm du moteur
	static void ajustementTimer1( uint8_t dureeA, uint8_t dureeB, uint8_t direction);

private:
	const uint8_t VITESSE;
	const uint8_t VITESSE_ROTATION;
};

#endif
