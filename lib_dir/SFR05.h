#ifndef SFR05_H
#define SFR05_H

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcm_so1602dtr_m.h"
#include "customprocs.h"
#include "lcm_so1602dtr_m_fw.h"

#define sonarDataPort DDRB
#define sonarDataDirection 0x01
#define sonarPORT PORTB
#define sonarPortPosition PORTA0

#define START_CLK 0x0A
#define START_CLK_N 0x02
#define STOP_CLK 0x08


class Sonar
{
	public:
		Sonar();
		unsigned int getEcho(void);
		void setup(void);
		void startTimer(unsigned int time);
		void waitForTimer(void);   
		void startRange(void);
};


#endif
