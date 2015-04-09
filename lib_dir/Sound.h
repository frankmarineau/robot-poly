#ifndef SONAR_H
#define SONAR_H

#include <avr/io.h>
#define F_CPU 80000000UL

#include <util/delay.h>
class Sound{

   public :
    
     void jouerSound(float frequence);
     void arreterSound();
    

};

#endif
