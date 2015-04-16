//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++ PROJET INTEGRATEUR 1ER ANNEE ++++++++++++++++++++++++++++++++++++//
// Departement de Genie Informatique et Genie Logiciel - Ecole Polytechnique de Montreal- H 2015  //
// Ecrit par : Foromo Daniel Soromou                                                              //
//             Hermann Charbel Racine Codo                                                        //
//             Esteban Sanchez                                                                    //
//             Francis Marineau                                                                   //
// Ecrit le Mardi 14 Avril 2015                                                                   //
// Presentation : Charlie est une robot automne, qui executera 3 taches distinte suivant les      //
//                indications du projet. Une fois qu'une tache est termine, elle continue a la    //
//                prochaine.                                                                      //
// Remarque : Pour les taches, les declarations sont faites dans les structures  pour une         //
//            question d'optimisation , car nous travaillons avec un microcontroller              //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
#include "setting.h"                    //Fichier d'entete indispensable a l'execution du main.cpp//
#include "Menu.h"                                                                                 //
#include "Tache.h"                                                                                //
#include "utility.h"                                                                              //
#include "Ports.h"                                                                                //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
int main()                                                                                        //
{                                                                                                 //
  LCM disp(&(lcdPortDirection), &(lcdPort));      //Intanciation d'un objet LCM, pour la LCD      //
  MENU tmpMenu(&disp);                            //Intanciation d'un objet Menu                  //
  Ports::initialiserPorts(&DDRA,&DDRB,&DDRC,&DDRD);      //Initialisation des ports               //
  Utility microControlleur;                 //Objet permettant de fixer les parametres du robot   //
  uint8_t selectedActionIndex ;                   //Stock la tache en cour d'execution            //
  selectedActionIndex =microControlleur.selectionTache(&tmpMenu);     //Execution du selecteur    //
  DDRD =0b11110001;                                                                               //
  switch(selectedActionIndex)              //Evaluation de la valeur de la tache selectionner     //
  {                                                                                               //
   	case T1:                                                                                  //
   	{                                                                                         //
   		Tache1 t1(&disp);      //Instanciation d'une tache1                               //
   		t1.run();              //Execution de la tache1                                   //
   	}                                                                                         //
   	case T2:                                                                                  //
   	{                                                                                         //
   		Tache2 t2(&disp);      //Instanciation d'une tache2                               //
   		t2.run();              //Execution de la tache2                                   //
   	}                                                                                         //
   	case T3:                                                                                  //
   	{                                                                                         //
   		Tache3 t3(&disp);      //Instanciation d'une tache3                               //
   		t3.run();              //Execution de la tache3                                   //
   	}                                                                                         //
  }                                                                                               //
  return 0;                                                                                       //
}                                                                                                 //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


