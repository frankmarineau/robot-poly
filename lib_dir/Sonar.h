#ifndef SONAR_H
#define SONAR_H

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
class Sonar{

   public:

    void initialisationTimer(void);     // initialisation of register for timer using
    unsigned int getEcho(void);         // send trigger pulse for detect any obstacle
    void setup(void);			// General  setup for port direction 
    void startTimer(unsigned int time);	// Starts the timer running for a number of uS defined by value of time
    void waitForTimer(void);		// Waits for the timer to stop

    


};

#endif
