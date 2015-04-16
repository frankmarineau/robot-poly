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
#include "Tache.h"


Tache1::Tache1(LCM* d)
{
	display = d;
}

Tache2::Tache2(LCM* d)
{
	display = d;
}

Tache3::Tache3(LCM* d)
{
	display = d;
}

void Tache1::run() {
	//Ajuster LCD
	display->clear();
	*display << "Tache 1";

	enum Transition {T_OFF, T_IN_PROGRESS, T_NEW_LINE, T_FINISH};

	Transition transitionState = T_OFF; // Indique l'etat de la transition
	bool fin = false; // Indique si le robot est arrivé à la fin
	uint8_t voie = 3; // Voie sur lequel le robot se trouve
	uint8_t nouvelleVoie = 0; // Nouvelle voie vers laquel le robot doit aller
	uint8_t nbChangements = 0; // Nombres de changements effectue

	Moteur moteur;
	Captor captor;
	Sound piezo;

	// Commencer tache
	moteur.avancer();

	// Boucle de la tache
	while (!fin) {

		if (transitionState == T_OFF) {
			// Détecter coupure
			if (captor.read() == VIDE) {
				// Selectionner la prochaine voie
				switch (voie) {
					case 1:
						nouvelleVoie = 2;
						break;
					case 2:
						nouvelleVoie = 3;
						break;
					case 3:
						if (nbChangements >= 2) { //Coupure de la fin
							fin = true;
						}
						else {
							nouvelleVoie = 2;
						}
						break;
					case 4:
						nouvelleVoie = 3;
						break;
					case 5:
						nouvelleVoie = 4;
						break;
				}
			}

			//Detecter photoresistance
			if (Photoresistance::getEtatEclairage() == DROITE_ECLAIRE && voie < 5) { // Droite
				nouvelleVoie = voie + 1;
				piezo.jouerSound(200, 300);
			}
			else if (Photoresistance::getEtatEclairage() == GAUCHE_ECLAIRE && voie > 1) { // Gauche
				nouvelleVoie = voie - 1;
				piezo.jouerSound(200, 300);
				piezo.jouerSound(800, 600);
			}

			// Initialiser transition
			if (nouvelleVoie != 0) {
				transitionState = T_IN_PROGRESS;
				nbChangements++;

				// Ajuster direction
				if (nouvelleVoie < voie) { // Commencer transition a Gauche
					moteur.avancer(-45);
					Utility::delay(200);
				}
				else if (nouvelleVoie > voie) { // Commencer transition a Droite
					moteur.avancer(45);
					Utility::delay(200);
				}
			}

			// Suivre ligne
			else {
				if (captor.read() == DROITE) {
					moteur.avancer(40);
				}
				else if (captor.read() == GAUCHE) {
					moteur.avancer(-40);
				}
				 else if (captor.read() == MILIEU) {
					moteur.avancer(0);
				}

			}
		}

		// En Transition
		else if (transitionState == T_IN_PROGRESS) {
			if ((nouvelleVoie < voie && captor.read() == DROITE) ||
				(nouvelleVoie > voie && captor.read() == GAUCHE)) {

				transitionState = T_FINISH;
			}
		}

		// Redresser robot
		else if (transitionState = T_FINISH) {
			if (nouvelleVoie < voie) { // Transition a gauche
				moteur.avancer(70); // redresser a droite
			}
			else if (nouvelleVoie > voie) { // Transition a Droite
				moteur.avancer(-70); // redresser a gauche
			}

			// Terminer transition
			if (captor.read() == MILIEU) {
				moteur.avancer(0);
				voie = nouvelleVoie;
				nouvelleVoie = 0;
				transitionState = T_OFF;
			}
		}
	}

	// Preparer TACHE 2
	// Aligner le centre de rotation
	moteur.avancer();
	Utility::delay(600);
	moteur.arreter();

	// Tourner vers la tache
	moteur.tournerGauche();
	while (captor.read() != MILIEU) {
		Utility::delay(10);
	}
	moteur.arreter();

}

void Tache2::attendreFinTournant() {
	Utility::delay(200);
	while (captor.read() != MILIEU) { Utility::delay(10); } // On attend d'avoir fini le tournant et d'être aligné avec le tape
}

void Tache2::run()
{
	//Ajuster LCD
	display->clear();
	*display << "Tache 2";


	LECTURE_LIGNE derniereLectureLigne;
	Sound piezo;

	// Première ligne droite avec les pointillés
	// moteur.avancer();
	// uint8_t nbEspacesTraverses = 0; // Nombre de petites coupures traversées
	// while (nbEspacesTraverses < 3) {
	// 	if (derniereLectureLigne == VIDE && captor.read() != VIDE) {
	// 		nbEspacesTraverses++;
	// 	}
	// 	derniereLectureLigne = captor.read();
	// 	Utility::delay(10);
	// }

	suivreLigne(6400, false);
	piezo.jouerSound(391, 200);
	suivreLigne(5000);
	Utility::delay(1100);
	moteur.arreter();
	Utility::delay(150);

	piezo.jouerSound(800, 300);

	// Ligne droite après les pointillés
	// Quand on arrive au coin, on commence le tournant de 90 degrés vers la gauche

	// Premier tournant de 90 degres
	moteur.tournerGauche();
	attendreFinTournant();
	moteur.arreter();
	Utility::delay(150);
	piezo.jouerSound(800, 300);
	suivreLigne(2500);
	moteur.arreter();
	Utility::delay(150);

	// Premier tournant sans ligne et ligne droite après
	moteur.tournerGauche();
	attendreFinTournant();
	moteur.arreter();
	Utility::delay(150);
	suivreLigne(14000);
	moteur.arreter();
	//piezo.jouerSound(800, 300);
	Utility::delay(150);

	// // Tournant a droite de 90 degres
	// moteur.tournerDroite();
	// attendreFinTournant();
	// moteur.arreter();
	// Utility::delay(50);
	// suivreLigne(2000);
	// moteur.arreter();
	// Utility::delay(50);

	// // Tournant à gauche sans ligne et ligne droite après
	// moteur.tournerGauche();
	// attendreFinTournant();
	// moteur.arreter();
	// Utility::delay(50);
	// suivreLigne(2000);
	// moteur.arreter();
	// Utility::delay(50);

	// // Tournant de 45 degrés à droite
	// // moteur.tournerDroite();
	// // attendreFinTournant();
	// // moteur.arreter();
	// // Utility::delay(50);
	// // moteur.avancer();

	// // Tournant de 90 degrés à la deuxième branche
	// bool tournantTraverse = false; // Nombre de petites coupures traversées
	// while (!tournantTraverse) {
	// 	if (derniereLectureLigne == MILIEU && captor.read() == DROITE)
	// 		tournantTraverse = true;
	// 	Utility::delay(10);
	// 	derniereLectureLigne = captor.read();
	// }
	// moteur.arreter();
	// Utility::delay(50);
	// moteur.tournerDroite();
	// attendreFinTournant();
	// moteur.arreter();
	// Utility::delay(50);

	// // Tournant de 135 degrés vers la gauche
	// moteur.tournerGauche();
	// attendreFinTournant();
	// moteur.arreter();
	// Utility::delay(50);
	// suivreLigne(1000);
	// moteur.avancer();

	// while (captor.read() != FULL) { Utility::delay(10); } // On attend d'arriver à la croix
	// Utility::delay(150);
	// moteur.arreter();

} // Fin de la tâche 2

// Suit la ligne pendant la durée en ms ou jusqu'à ce que la ligne s'arrête (un tournant de 90 degrés compte comme une "fin" de ligne)
void Tache2::suivreLigne(uint16_t duree, bool arreterSiVide) {
	Sound piezo;
	uint16_t i = 0;
	bool finLigne = false;
	while (i < duree/10 && !finLigne) {
		if (captor.read() == MILIEU) {
			moteur.avancer();
		}
		else if (captor.read() == GAUCHE) {
			moteur.avancer(-40);
		}
		else if (captor.read() == DROITE) {
			moteur.avancer(40);
		}
		else if (captor.read() == VIDE) {
			if (arreterSiVide) {
				finLigne = true;
			}
			else {
				moteur.avancer();
			}
		}

		Utility::delay(10);
		i++;
	}
}

//+++++++++++++++++++++++++++++++++++ Sound::arreterSound(void) ++++++++++++++++++++++++++++++++++++++++++//
// Description     : Arreter le son en cour de lecteur                                                    //
// Type de methode : Public                                                                               //
// Parametre(s)    : Aucun                                                                                //
// Valeur de retour: Aucune                                                                                                                             //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Tache3::run()                                                                                                                                      //
{
	//Ajuster LCD
	display->clear();
	*display << "Tache 3";

	                                                                                                                                               //
	Sound piezo;                                                                                                                                    //
	piezo.jouerSound(391);                                                                                                                          //
	Utility::delay(2000);                                                                                                                           //
	piezo.arreterSound();                                                                                                                           //
	Sonar sonar;                                                                                                                                    //
	Moteur moteur;                                                                                                                                  //
	Captor capteur;                                                                                                                                 //
	uint8_t range;                                                                                                                                  //
	int i = 0, j = 0, phase = 0;                                                                                                                    //
	for(phase = 1; phase <= 2; ++phase)                                                                                                             //
	{                                                                                                                                               //
		for(j = 1; j <= 8; ++j)                                                                                                                 //
		{                                                                                                                                       //
			for(i = 1; i <= 15; ++i)                                                                                                        //
			{                                                                                                                               //
			  display->clear();                                                                                                             //
				sonar.sendPulse();			                                                                                //
				range = sonar.receivePulse();		                                                                                //
				*display << "Tache 3         Dst: ";                                                                                    //
				*display << range ;                                                                                                     //
				*display << "inch";                                                                                                     //
				_delay_ms(67);                                                                                                          //
				if (range > 24)                                                                                                         //
				{                                                                                                                       //
					moteur.ajustementTimer1(0,0,DIRECTION_AVANCE);                                                                  //
				}                                                                                                                       //
				else                                                                                                                    //
				{                                                                                                                       //
					if (phase == 1)                                                                                                 //
					{                                                                                                               //
						moteur.ajustementTimer1(uint8_t(255-range*6.875),uint8_t(255-range*6.875),DIRECTION_DROITE);            //
					}                                                                                                               //
					else                                                                                                            //
					{                                                                                                               //
						moteur.ajustementTimer1(uint8_t(255-range*6.875),uint8_t(255-range*6.875),DIRECTION_GAUCHE);            //
					}                                                                                                               //
					switch (capteur.readValue())                                                                                    //
					{
					   	                                                                                                               //
					    case 0b10000: piezo.jouerSound(392); break;
					    case 0b11000:                                           //
					    case 0b01000: piezo.jouerSound(349); break;
					    case 0b01100:
					    case 0b00100: piezo.jouerSound(330); break;
					    case 0b00110:                                                         //
					    case 0b00010: piezo.jouerSound(294); break;                                                                 //
					    case 0b00011:
					    case 0b00001: piezo.jouerSound(262); break;                                                                 //
					    default : piezo.arreterSound();                        //Ne pas jouer du son, s'il nya pas de significative //
					}                                                                                                               //
				}                                                                                                                       //
			}                                                                                                                               //
			_delay_ms(9);                                                               //Attendre un delay de 9ms pour attiendre 1seconde  //
		}                                                                                                                                       //
	}                                                                                                                                               //
	moteur.ajustementTimer1(0,0,DIRECTION_AVANCE);                                             //Arreter le robot a la fin du parcour               //
	piezo.arreterSound();                                                                      //Arreter le son , s'il y en avait qui jouait        //
	display->clear();                                                                          //Nettoyer la LCD                                    //
	*display << "Termine         Merci!";                                                      //Fin d'execution des tache                          //
}                                                                                                                                                       //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

