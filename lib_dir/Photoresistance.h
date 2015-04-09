#ifndef PHOTORESISTANCE_H
#define PHOTORESISTANCE_H

#include <avr/io.h>
#include "can.h"
class Photoresistance {

public:

  static bool estEclaireAGauche();
  static bool estEclaireADroite();

};

#endif
