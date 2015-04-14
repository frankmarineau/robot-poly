#include "captor.h"


Captor::Captor()
{
        DDR = &(DDRA);
        *DDR = 0x00;
        
        PORT = &(PINA);
}

Captor::Captor(uint8_t *dataDirection, uint8_t *portIndex)
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
    if ((*PORT) & 0x04){
    	return MILIEU;
    }
    else {
    	return UNKNOWN;
    }
}
