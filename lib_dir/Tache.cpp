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
	Utility mc;
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
					mc.ajustementTimer2(0,0,0x00);
				}
				else
				{
					if (phase ==1)  
					{
						mc.ajustementTimer2(uint8_t(255-range*6.875),uint8_t(255-range*6.875),0x02);
					}
					else           
					{
						 mc.ajustementTimer2(uint8_t(255-range*6.875),uint8_t(255-range*6.875),0x01);
					}
				}
			}
			_delay_ms(9);
		}
	}
	mc.ajustementTimer2(0,0,0x00);
	display->clear();
	*display << "Terminer         Merci!";
	
}
