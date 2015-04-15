#ifndef PHOTORESISTANCE_H
#define PHOTORESISTANCE_H

#include <avr/io.h>
#include "can.h"

enum DirectionPhotoresistance { GAUCHE_ECLAIRE, DROITE_ECLAIRE, RIEN_ECLAIRE };

class Photoresistance {

public:
  static DirectionPhotoresistance getEtatEclairage();
  static bool estEclaireAGauche();
  static bool estEclaireADroite();

};

#endif
