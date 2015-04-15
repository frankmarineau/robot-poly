#ifndef MOTEUR_H
#define MOTEUR_H

#include <avr/io.h>
#include "utility.h"

class Moteur {
public:
	Moteur(uint8_t vitesse = 150);

	// Avance dans une certaine direction - entre -90 et 90
	void avancer(uint8_t direction = 0);
	// Recule dans une certaine direction - entre -90 et 90
	void reculer(uint8_t direction = 0);
	// Tourne sur place d'un certain nombre de degrée - négatif si anti-horaire
	void tournerDroite(uint8_t vitesse = 120);
	void tournerGauche(uint8_t vitesse = 120);
	//Arrete de bouger
	void arreter();

	//Ajuster le timer pour générer le pwm du moteur
	void ajustementTimer1( uint8_t dureeA, uint8_t dureeB, uint8_t direction);

private:
	

	const uint8_t VITESSE;
};

#endif
