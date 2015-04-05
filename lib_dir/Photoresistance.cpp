#include "Photoresistance.h"
#include "Ports.h"

static const uint8_t SEUIL_ECLAIRAGE = 0xEE;

Photoresistance::estEclaireAGauche() {
  return (Ports.getPhotoresistanceGauche() > SEUIL_ECLAIRAGE);
}

Photoresistance::estEclaireADroite() {
  return (Ports.getPhotoresistanceDroite() > SEUIL_ECLAIRAGE);
}