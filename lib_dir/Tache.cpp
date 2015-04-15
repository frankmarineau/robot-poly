#include "Tache.h"




Tache1::Tache1(LCM* d)
{
	display =d;
}

Tache2::Tache2(LCM* d)
{

	display =d;
}

Tache3::Tache3(LCM* d)
{
	display =d;
}


    
void Tache1::run()
{
	bool enTransition = false; // Indique si le robot est en transition
	bool fin = false; // Indique si le robot est arrivé à la fin
	uint8_t voie = 3; // Voie sur lequel le robot se trouve
	uint8_t nouvelleVoie = 0; // Nouvelle voie vers laquel le robot doit aller
	uint8_t nbChangements; // Nombres de changements effectue

	Moteur moteur;
	Captor captor(&DDRA, &PORTA);

	//Commencer tache
	moteur.avancer();

	//Boucle de la tache
	while (!fin){
		if (!enTransition) {
			

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
						if (nbChangements >= 2){ //Coupure de la fin
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

			// Détecter lumiere


			// Initialiser transition
			if (nouvelleVoie != 0) {
				enTransition = true;
				nbChangements++;

				// Ajuster direction
				if (nouvelleVoie < voie){ // Transition a Gauche
					moteur.avancer(-75);
				}
				else if (nouvelleVoie > voie){ // Transition a Droite
					moteur.avancer(75);
				}
			}

		}

		else { //En Transition

			// Redresser direction
			if (nouvelleVoie < voie && captor.read() == DROITE){ // Transition a gauche
				moteur.avancer(50);
			}
			else if (nouvelleVoie > voie && captor.read() == GAUCHE){ // Transition a Droite
				moteur.avancer(-50);
			}
			
			// Terminer transition
			else if (captor.read() == MILIEU) {
				moteur.avancer(0);
				voie = nouvelleVoie;
				nouvelleVoie = 0;
				enTransition = false;

			}
		}
		
	}

	// Preparer tache 2

}

void Tache2::run()
{
	
}

//++++++++++++++++++++ REALIATION DE LA TACHE 3 ++++++++++++++++++++++++++++++//
void Tache3::run()
{
	
	//+++++++++++++Sound de demarrage de la tache 3+++++++++++++++++++++++//
	Sound piezo;
	piezo.jouerSound(); //Demarrer le son
	_delay_ms(2000);// Attendre pendant 2 secondes sans rien faire
	piezo.arreterSound(); //Arreter le son
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	
	Sonar sonar;
	
	sonar.setup();
	
	uint8_t range;    
	int i =0, j =0, phase =0;
	Moteur moteur;
	for(phase = 1; phase <=2; ++phase)
	{	
		for(j =1; j<=8 ; ++j)
		{
			for(i =1; i<=15 ; ++i)
			{
			        display->clear();
			        
				sonar.startRange();			// Send a high on the trigger pin to start a ranging
				
				range = sonar.getEcho();		// Wait for the echo line to go high and then measure the length of this high
				PORTD =0x08;
				*display << "Tache 3         Dst: ";		
				*display << range ;
				*display << "inch";
				_delay_ms(67);
				
				
				if (range >24)
				{
					moteur.ajustementTimer1(0,0,0x00);
				}
				else
				{
					if (phase ==1)  
					{
						moteur.ajustementTimer1(uint8_t(255-range*6.875),uint8_t(255-range*6.875),0x02);
					}
					else           
					{
						 moteur.ajustementTimer1(uint8_t(255-range*6.875),uint8_t(255-range*6.875),0x01);
					}
				}
			}
			_delay_ms(9);
		}
	}
	moteur.ajustementTimer1(0,0,0x00);
	display->clear();
	*display << "Terminer         Merci!";
	
}
