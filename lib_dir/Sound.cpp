//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Jouer un son avec une frequence fournir.                                                 //
//                                                                                                        //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#include "Sound.h"                                                                                        //
#include "setting.h"                                                                                      //
                                                                                                          //
//++++++++++++++++++++++++++++ Sound::jouerSound(uint16_t frequence) +++++++++++++++++++++++++++++++++++++//
// Description     : Jouer le son correspondant a une frequence donee                                     //
// Type de methode : Public                                                                               //
// Parametre(s)    : uint16_t frequence, frequence de la note a jouer                                     //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Sound::jouerSound(uint16_t frequence, uint16_t duree)                             //Entete de la fonction            //
{                                                                                                         //
     TCCR2A |= (1<<WGM21)|(1<<COM2A0) | (1 << COM2B0);                 //Activer le mode CTC              //
     TCCR2B = (1<<CS22) | (1 << CS21) | (1 << CS20);                   //Fixer prescaler 1024             //
     OCR2A =  F_CPU /2048/frequence;                                   //Cacul de OCR2A correspondant     //
     if (duree != 0) {
      Utility::delay(duree);                                                                                                                           //
      arreterSound();
     }
}                                                                                                         //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//+++++++++++++++++++++++++++++++++++ Sound::arreterSound(void) ++++++++++++++++++++++++++++++++++++++++++//
// Description     : Arreter le son en cour de lecteur                                                    //
// Type de methode : Public                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Sound::arreterSound(void)                                         //Entete de la fonction            //
{                                                                                                         //
  TCCR2B &= 0x00;                                                      //Desactiver le prescaler          //
}                                                                                                         //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
