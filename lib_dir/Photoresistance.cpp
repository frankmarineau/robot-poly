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
    if (ajustementGauche < 160){
      seuilGauche = 35;
    }
    else if (ajustementGauche < 210) {
      seuilGauche = 20;
    }
    else if (ajustementGauche < 235) {
      seuilGauche = 10;
    }
    else {
      seuilGauche = 5;
    }

    if (ajustementGauche < 160){
      seuilDroite = 35;
    }
    else if (ajustementGauche < 210) {
      seuilDroite = 20;
    }
    else if (ajustementGauche < 235) {
      seuilDroite = 10;
    }
    else {
      seuilDroite = 5;
    }

}

uint16_t Photoresistance::eclairageGauche() {
  uint16_t eclairage = Ports::lirePhotoresistanceGauche();
  if (ajustementGauche > eclairage) {
    eclairage = 0;
  }
  else {
    eclairage -= ajustementGauche;
  }

  return eclairage;
}

uint16_t Photoresistance::eclairageDroite() {
  uint16_t eclairage = Ports::lirePhotoresistanceDroite();
  if (ajustementDroite > eclairage) {
    eclairage = 0;
  }
  else {
    eclairage -= ajustementDroite;
  }
  
  return eclairage;
}

DirectionPhotoresistance Photoresistance::getEtatEclairage() {
    
  // Si une photoresistance est eclairee
  if (eclairageDroite() > seuilDroite || eclairageGauche() > seuilGauche) {
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

    //DEBUGGAGE
    /*d->clear();
    *d << ajustementGauche;
    *d << " ";
    *d << ajustementDroite;

    *d << " ";
    *d << seuilGauche;
    *d << "    ";
    *d << seuilDroite;

    *d << " E ";
    *d << eclairageGauche();
    *d << " ";
    *d << eclairageDroite();*/

}