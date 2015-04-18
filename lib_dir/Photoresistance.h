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
  uint16_t eclairageGauche();
  uint16_t eclairageDroite();

private:
	uint16_t ajustementGauche;
	uint16_t ajustementDroite;
	uint16_t seuilGauche;
	uint16_t seuilDroite;

};

#endif
