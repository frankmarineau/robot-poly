#ifndef SONAR_H
#define SONAR_H

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcm_so1602dtr_m.h"
#include "customprocs.h"
#include "lcm_so1602dtr_m_fw.h"

#define sonarDataPort
#define sonarDataDirection 0x01
#define sonarPORT PORTB
#define sonarPortPosition PORTA0


#define START_CLK	0x0A				// Start clock with 1:8 prescaler CTC mode
#define START_CLK_N	0x02				// Start clock running 1:8 prescaler in normal mode
#define STOP_CLK	0x08				// Stop clock
#define LCD03		0xC6				// Address of LCD03
     
     
  
class Sonar{
private:
    uint16_t distance;
    LCM *display;

public:
    Sonar();
    void initialisationTimer(void);     // initialisation of register for timer using
    unsigned int getEcho(void);         // send trigger pulse for detect any obstacle
    void setup(void);			// General  setup for port direction 
    void startTimer(unsigned int time);	// Starts the timer running for a number of uS defined by value of time
    void waitForTimer(void);		// Waits for the timer to stop
    
};

#endif
