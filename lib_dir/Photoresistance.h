#ifndef PHOTORESISTANCE_H
#define PHOTORESISTANCE_H

#include <avr/io.h>
#include "can.h"
#include "utility.h"

enum DirectionPhotoresistance { GAUCHE_ECLAIRE, DROITE_ECLAIRE, RIEN_ECLAIRE };

class Photoresistance {

public:
Photoresistance();  
  void calibrer();
  DirectionPhotoresistance getEtatEclairage();
  uint8_t eclairageGauche();
  uint8_t eclairageDroite();

private:
	uint8_t ajustementGauche;
	uint8_t ajustementDroite;
	uint8_t seuilGauche;
	uint8_t seuilDroite;

};

#endif
