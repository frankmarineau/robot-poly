#ifndef SONAR_H
#define SONAR_H

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
class Sonar{

   public:

    
     void envoiDuTrigerPulse();
     void receptionDuSignal();


};

#endif
