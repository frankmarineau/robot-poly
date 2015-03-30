/*
 * Groupe 0340
 * Description : Main
*/

#include "moteur.h"
#include "utility.h"

int main() {
	//Initialisation 
	DDRD = 0xff;

	Moteur moteur();
	moteur.avancer(90);

	Utility::delay(2000);
	moteur.arreter();


  return 0;
}



