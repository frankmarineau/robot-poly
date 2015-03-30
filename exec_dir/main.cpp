/*
 * Groupe 0340
 * Description : Main
*/

#include "moteur.h"
#include "utility.h"

int main() {
	//Initialisation 
	DDRD = 0xff;

	Moteur moteur;
	//moteur.reculer(0);

	moteur.avancer(45);
	Utility::delay(5000);
	moteur.arreter();

	/*Utility::delay(2000);
	moteur.avancer(20);
	Utility::delay(6000);
	moteur.arreter();*/
	Utility::delay(2000);

	moteur.tourner(360);


  return 0;
}



