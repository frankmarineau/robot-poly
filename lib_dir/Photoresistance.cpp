#include "Photoresistance.h"
#include "Ports.h"

static const uint8_t SEUIL_ECLAIRAGE = 0xf0;
static const uint8_t SEUIL_DIFFERENCE = 0x20;

bool Photoresistance::estEclaireAGauche() {
  return Ports::lirePhotoresistanceGauche() > SEUIL_ECLAIRAGE;
}

bool Photoresistance::estEclaireADroite() {
  return Ports::lirePhotoresistanceDroite() > SEUIL_ECLAIRAGE;
}

DirectionPhotoresistance Photoresistance::getEtatEclairage() {
  if (!estEclaireADroite() && !estEclaireAGauche()) return RIEN_ECLAIRE;

  uint8_t differenceEclairage = Ports::lirePhotoresistanceDroite() - Ports::lirePhotoresistanceGauche();
  differenceEclairage = (differenceEclairage < 0 ? -differenceEclairage : differenceEclairage);
  if (differenceEclairage < SEUIL_DIFFERENCE) return RIEN_ECLAIRE;

  if (Ports::lirePhotoresistanceDroite() > Ports::lirePhotoresistanceGauche()) {
    return DROITE_ECLAIRE;
  }
  else {
    return GAUCHE_ECLAIRE;
  }
}