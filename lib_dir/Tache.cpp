#include "Tache.h"

Tache::Tache()
{
	status_ = false;
}

inline void Tache::setStatus (bool status)
{ 
	status_ = status;
}

inline bool Tache::getStatus (void) 
{ 
	return status_;
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
	Sound s;
	s.jouerSound(); //Demarrer le son
	_delay_ms(2000);// Attendre pendant 2 secondes sans rien faire
	s.arreterSound(); //Arreter le son
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	
	
}
