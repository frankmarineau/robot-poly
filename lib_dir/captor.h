#ifndef CAPTOR_H
#define CAPTOR_H
#include "setting.h"

class Captor
{
private:
     volatile uint8_t *DDR;
     volatile uint8_t *PORT;   
public:
     Captor();
     Captor(uint8_t *dataDirection, uint8_t *portIndex);
     ~Captor();     
     uint8_t read();
};

#endif
