//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Structure de controle pour la gestion du menu                                            //
//               est activer par defaut.                                                                  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#ifndef MENU_H                                  //Verifier l'inclusion du fichier                         //              
#define MENU_H                                  //Definir le fichier s'il n'est pas inclus                //
	#include "setting.h"                        //Inclusion du fichier setting.h                      //
	enum TACHENUMBER {T1, T2, T3};              //Litteral pour identifier les differentes taches     //
	enum MODE {MODE1,MODE2, MODE3};             //Litteral pour identifer les differentes modes       //
	class MENU                                  //Definition de la classe menu                        //
	{                                                                                                 //
	     private:                               //Declaration des membres prives                      //
		MODE menuState;                         //L'etat du menu                                  //
		LCM *display;                           //L'adresse de la LCD utilisee                    //
	     	void afficherMenu(void);                //Affichage d'un menu                             //
	     public :                               //Declaration des membres publics                     //
	     	MENU(LCM *disp);                        //Contructeur                                     //
	     	void changeState(void);                 //Changer d'etat                                  //
	     	TACHENUMBER activeTache(void);     	//Selection une tache                             //
	};                                          //Fin de la definition dee la classe                  //
#endif                                        //Fin de la definition  du contenu du fichier               //        
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
