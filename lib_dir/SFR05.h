//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Structure du programme de detection des obstacles                                        //
//                                                                                                        //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#ifndef SFR05_H                                      //Verification de la double inclusions               //
#define SFR05_H                                      //Inclusion du fichier , s'il n'est pas inclus       //
	#include "setting.h"                                                                              //
	class Sonar                                                                                       //
	{                                                                                                 //
		public:                                                                                   //
			Sonar();                             //Constructeur de la classe                  //
			uint16_t receivePulse(void);         //Revevoir une onde                          //
			void startTimer(uint16_t time);      //Demarrer un timer                          //
			void waitForTimer(void);             //Attendre l'ecoulement d'un temps           //
			void sendPulse(void);                //Envoie d'une onde                          //
	};                                                                                                //
#endif                                                                                                    //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
