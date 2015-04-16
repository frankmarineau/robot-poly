//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//+++++++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE +++++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015          //
// Ecrit par : Foromo Daniel Soromou                                                                      //
//             Hermann Charbel Racine Codo                                                                //
//             Esteban Sanchez                                                                            //
//             Francis Marineau                                                                           //
// Ecrit le Mardi 14 Avril 2015                                                                           //
// Description : Ce code permet de gerer le choix de la tache desire. Dans un premier temps, le mode 1    //
//               est activer par defaut.                                                                  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#include "Menu.h"                                                                                         //
//++++++++++++++++++++++++++++++++++++++ MENU::affichierMenu(void) +++++++++++++++++++++++++++++++++++++++//
// Description     : Cette fonction permet d'afficher sur la LCD , le texte correspondant a l'etat actuel //
//                   du menu.                                                                             //
// Type de methode : Privee                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void MENU::afficherMenu(void)                                  //entete de la fonction                    //
{                                                              //Debut de la fonction                     //
  display->clear();                                            //Nettoyer la LCD                          //
  switch(menuState)                                            //Analyse selon l'etat du menu             //
  {                                                            //Debut de la structure de controle        //
    case MODE1: display->write("Mode 1"); break;                   //Affichage du texte du mode 1         //
    case MODE2: display->write("Mode 2"); break;                   //Affichage du texte du mode 2         //
    case MODE3: display->write("Mode 3"); break;                   //Affichage du texte du mode 3         //
  }                                                            //Fin de la strucutre de controle          //
}                                                              //Fin de la fonction                       //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//+++++++++++++++++++++++++++++++++++++ MENU::MENU(LCM *disp)+++++++++++++++++++++++++++++++++++++++++++++//
// Description     : (Constructeur) Initialisation des attributs de la classe.                            //
// Type de methode : Public                                                                               //
// Parametre(s)    : LCM *disp, un pointeur vers une LCM, pour l'utilisation de la LCD                    //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
MENU::MENU(LCM *disp)                                          //entete de la fonction                    //
{                                                              //Debut de la fonction                     //                                                            
  menuState = MODE1;                                           //MODE1 est le mode de depart              //                                       
  display = disp;                                              //Initialisation de la display             //
  afficherMenu();                                              //Afficher le menu de depart               //
}                                                              //Fin de la fonction                       //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//+++++++++++++++++++++++++++++++++++++ MENU::changeState(void)+++++++++++++++++++++++++++++++++++++++++++//
// Description     : Changer d'etat chaque fois que le bouton de selection est appuyer                    //
// Type de methode : Public                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void MENU::changeState(void)                                    //Entete de la fonction                   //
{                                                               //Debut de la fonction                    //
  switch(menuState)                                             //Analyse selon l'etat du menu            //
  {                                                             //Debut de la structure de controle       //
    case MODE1: menuState = MODE2; break;                          //Changement pour le MODE2             //
    case MODE2: menuState = MODE3; break;                          //Changement pour le MODE3             //
    case MODE3: menuState = MODE1; break;                          //Changement pour le MODE1             //
  }                                                             //Fin de la structure de controle         //                                              
  afficherMenu();                                               //Afficher le menu du nouvel etat         //
}                                                               //Fin de la fonction                      //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
                                                                                                          //
//+++++++++++++++++++++++++++++++++++++ MENU::MENU(LCM *disp +++++++++++++++++++++++++++++++++++++++++++++//
// Description     : Activer une tache                                                                    //
// Type de methode : Public                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                               //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
TACHENUMBER MENU::activeTache(void)                             //Entete de la fonction                   //
{                                                               //Debut de la fonction                    //
  switch(menuState)                                             //Analyse selon l'etat du menu            //
  {                                                             //Debut de la structure de controle       //
  	case MODE1: display->write("Tache 1"); return T1;          //Retourner l'index T1                 //
  	case MODE2: display->write("Tache 2"); return T2;          //Retourner l'index T2                 //
  	case MODE3: display->write("Tache 3"); return T3;          //Retourner l'index T3                 //
  }                                                             //Fin de la structure de controle         //
}                                                               //Fin de la fonction                      //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
