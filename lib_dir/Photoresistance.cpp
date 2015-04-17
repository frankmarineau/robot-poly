#include "Photoresistance.h"
#include "Ports.h"

Photoresistance::Photoresistance()
{

}

void Photoresistance::calibrer() {
    uint16_t valGauche = 0;
    uint16_t valDroite = 0;

    // Lecture des valeurs
    for (uint8_t i = 0; i < 50; i++){
      Utility::delay(4);
      valGauche += Ports::lirePhotoresistanceGauche();
      valDroite += Ports::lirePhotoresistanceDroite();
    }
    // Moyenne
    ajustementGauche = round(valGauche / 50);
    ajustementDroite = round(valDroite / 50);


    // Ajuster seuils
    if (ajustementGauche < 155){
      seuilGauche = 30;
    }
    else {
      seuilGauche = 30 - (27 * (100 - (250 - ajustementGauche) / 100));
    }

    if (ajustementDroite < 155){
      seuilDroite = 30;
    }
    else {
      seuilDroite = 30 - (27 * (100 - (250 - ajustementDroite) / 100));
    }
}

uint8_t Photoresistance::eclairageGauche() {
  int16_t eclairage = Ports::lirePhotoresistanceGauche() - ajustementGauche;
  if (eclairage < 0) {
    eclairage = 0;
  }

  return eclairage;
}

uint8_t Photoresistance::eclairageDroite() {
  int16_t eclairage = Ports::lirePhotoresistanceDroite() - ajustementDroite;
  if (eclairage < 0) {
    eclairage = 0;
  }
  
  return eclairage;
}

DirectionPhotoresistance Photoresistance::getEtatEclairage() {
  // Si une photoresistance est eclairee
  if (eclairageDroite() > 0x17 || eclairageGauche() > 0x17) {
    if (eclairageDroite() > eclairageGauche()){
      return DROITE_ECLAIRE;
    }
    else if (eclairageDroite() < eclairageGauche()){
      return GAUCHE_ECLAIRE;
    }
    else {
      return RIEN_ECLAIRE;
    }
  }
  else {
    return RIEN_ECLAIRE;
  }



  /*if (!estEclaireADroite() && !estEclaireAGauche()) return RIEN_ECLAIRE;

  uint8_t differenceEclairage = Ports::lirePhotoresistanceDroite() - Ports::lirePhotoresistanceGauche();
  differenceEclairage = (differenceEclairage < 0 ? -differenceEclairage : differenceEclairage);
  if (differenceEclairage < SEUIL_DIFFERENCE) return RIEN_ECLAIRE;

  if (Ports::lirePhotoresistanceDroite() > Ports::lirePhotoresistanceGauche()) {
    return DROITE_ECLAIRE;
  }
  else {
    return GAUCHE_ECLAIRE;
  }*/
}