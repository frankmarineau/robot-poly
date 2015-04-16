//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE ++++++++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Ce fichier d'entete, fixe l'ensemble des fichiers d'entete necessaire pour la            //
//               la realisation du projet. En plus, il fixe aussi les entrees/sorties pour les            //
//               differents composants utilises et autres constantes.                                     //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#ifndef SETTING_H                                //Verifier si le fichier d'entete a ete deja includemmmm //
#define SETTING_H                                //Inclure le fihcier, s'il n'est pas inclus              //
	//+++++++++++++++++++++ INCLUSION DES FICHIERS D'ENTETES NECESSAIRE ++++++++++++++++++++++++++++++//
	#include <avr/io.h>                      //Fichier d'entete pour l'ensemble des entrees sorties   //
	#include <avr/interrupt.h>		 //Fichier d'entete pour l'ensemble des interruptions I/E //
	#define F_CPU 8000000UL                  //Macro pour fixer la frequence du micro-controllleur    //
	#include <util/delay.h>                  //Fichier d'entete pour l'utilisation de _delay_xx       //
	#include "lcm_so1602dtr_m_fw.h"          //Fichier d'entete necessaire a l'utilisation de la LCD  //
	#include "customprocs.h"		 //Fichier d'entete necessaire a l'utilisation de la LCD  //
	#include <stdlib.h>                                                                               //
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
	//+++++++++++++++++++++ VALEUR DES DATA DIRECTIONS REGISTRER (DDR)++++++++++++++++++++++++++++++++//
	#define DDRA_VALUE 0x00                  //Tout les composants sur le port envoi des donners au mc//
	#define DDRB_VALUE 0xFC                  // 11 11 11 00 , donne la direction de chaque pin        // 
	#define DDRC_VALUE 0xFF                  //Toute les pins sont en sortie, utilisee pour la lcd    //
	#define DDRD_VALUE 0xFC                 //Toute les pins sont en sortie, utiliser pour les mot    //
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
	//++++++++++++++++++ PARAMETRE DES BOUTON POUSOIR POUR LE MENU ET DES TYPES ++++++++++++++++++++++//
	#define bouton1PIN PIND                  //La pin de connection pour le bouton 1 (Selecteur)      //
	#define bouton1ClearValue 0x04           //Valeur de comparaison pour le bouton 1                 //
	#define bouton2PIN PIND			 //La pin de connection pour le bouton 2 (Validateur)     //
	#define bouton2ClearValue 0x08		 //Valeur de comparaison pour le bouton 2                 //
	#define debounceTime 10			 //Temps d'anti rebond, fixer a 10ms                      //
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
	//+++++++++++++++++++ PARAMETRES DU SONAR  ET DES CONSTANTES +++++++++++++++++++++++++++++++++++++//
	#define START_CLK 0x0A                   //Constante de demarrage de la clok                      //
	#define START_CLK_N 0x02                 //                                                       //
	#define STOP_CLK 0x08                    //Constante d'arret de la clock                          //
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
	//++++++++++++++++++++++++++++++ PORTS UTILISER PAR LA LCD +++++++++++++++++++++++++++++++++++++++//
	#define  lcdPortDirection DDRC                                                                    //
	#define  lcdPort PORTC                                                                            //
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#endif                                            //Fin de la struture de controle de la double inclusion //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
