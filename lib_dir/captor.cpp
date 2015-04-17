//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Utilisation du suiveur de ligne de la detection des differentes positions du robot       //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#include "captor.h"                                                                                       //
Captor::Captor()
{
    DDR = &(DDRA);
    *DDR = 0x00;
    PIN = &(PINA);
}

Captor::Captor(volatile uint8_t *dataDirection, volatile uint8_t *pinIndex)
{
    DDR = dataDirection;
    *DDR = 0x00;
    PIN = pinIndex;
}



LECTURE_LIGNE Captor::read()
{
    if (((*PIN) & 0x04) >= 1 && ((*PIN) & 0x1B) == 0){
    	return MILIEU;
    }
    else if (((*PIN) & 0x03) >= 1 && ((*PIN) & 0x18) == 0){
    	return DROITE;
    }
    else if (((*PIN) & 0x03) == 0 && ((*PIN) & 0x18) >= 1){
    	return GAUCHE;
    }
    else if (((*PIN) & 0x1F) == 0){
    	return VIDE;
    }
    else if (((*PIN) & 0x1f) == 0x1f){
    	return FULL;
    }
    else {
    	return UNKNOWN;
    }
}


uint8_t Captor::readValue()
{	
     return ((*PIN) & 0x1f);
}
