//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Structure de gestion de la lecture du son                                                //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#ifndef SONAR_H                                                                                           //
#define SONAR_H                                                                                           //
	#include "setting.h"                                                                              //
	#include "utility.h"                                                                              //
	class Sound                                                                                       //
	{                                                                                                 //
	   public :                                                                                       //
	     void jouerSound(uint16_t frequence, uint16_t duree = 0);//Jouer du son avec une frequence    //
	     void arreterSound(void);                                //Arreter le son                     //
	};                                                                                                //
#endif                                                                                                    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
