//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Structure de controle du suiveur de ligne                                                //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#ifndef CAPTOR_H                                                                                          //
	#define CAPTOR_H                                                                                  //
	#include "setting.h"                                                                              //
	enum LECTURE_LIGNE {                                                                              //
		GAUCHE,                                                                                   // 
		MILIEU,                                                                                   //
		DROITE,                                                                                   //
		VIDE,                                                                                     //
		FULL,                                                                                     //
		UNKNOWN                                                                                   //
	};                                                                                                //
	class Captor                                                                                      //
	{                                                                                                 //
	private:                                                                                          //
	     volatile uint8_t *DDR;                                                                       //
	     volatile uint8_t *PIN;                                                                      //
	public:                                                                                           //
	     Captor();                                                                                    //
	     Captor(volatile uint8_t *dataDirection, volatile uint8_t *pinIndex);                        //
	     LECTURE_LIGNE read();                                                                        //
	     uint8_t readValue();  
                                                                    //
	};                                                                                                //
#endif                                                                                                    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
