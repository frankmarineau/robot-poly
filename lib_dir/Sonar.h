#ifndef SONAR_H
#define SONAR_H

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

class Sonar{

   private:
   	uint8_t distance_;
   public:
     Sonar();    
     uint8_t getDistance();
     void setDistance(uint8_t d) ;
     uint8_t readDistance();
};

#endif
