#ifndef SFR05_H
#define SFR05_H

#include "setting.h"



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
