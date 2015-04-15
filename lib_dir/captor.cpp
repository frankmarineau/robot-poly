#include "captor.h"


Captor::Captor()
{
    DDR = &(DDRA);
    *DDR = 0x00;

    PORT = &(PINA);
}

Captor::Captor(volatile uint8_t *dataDirection, volatile uint8_t *portIndex)
{
    DDR = dataDirection;
    *DDR = 0x00;

    PORT = portIndex;
}


Captor::~Captor()
{

}


LECTURE_LIGNE Captor::read()
{
    if (((*PORT) & 0x04) > 1 && ((*PORT) & 0x1B) == 0){
    	return MILIEU;
    }
    else if (((*PORT) & 0x03) > 1 && ((*PORT) & 0x18) == 0){
    	return DROITE;
    }
    else if (((*PORT) & 0x03) == 0 && ((*PORT) & 0x18) > 1){
    	return GAUCHE;
    }
    else if (((*PORT) & 0x1F) == 0){
    	return VIDE;
    }
    else if (((*PORT) & 0x1f) == 0x1f){
    	return FULL;
    }
    else {
    	return UNKNOWN;
    }
}

uint8_t Captor::readValue()
{	
     return ((*PORT) & 0x1f);
}
