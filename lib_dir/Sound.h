#ifndef SONAR_H
#define SONAR_H

#include "setting.h"
#include "utility.h"

class Sound{

   public :
    
     void jouerSound(uint16_t frequence, uint8_t tempsMs = 0);
     void arreterSound();
};

#endif
