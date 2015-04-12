#ifndef MENU_H
#define MENU_H



#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"

#define bouton1PIN PINB
#define bouton1ClearValue 0x01
#define bouton2PIN PINB
#define bouton2ClearValue 0x02
#define debounceTime 10

enum TACHENUMBER {T1, T2, T3};
enum MODE {MODE1,MODE2, MODE3};
class MENU
{
     private:
        MODE menuState;
        LCM *display;
     	void afficherMenu(void);
     public :
     	MENU(LCM *disp);
     	void changeState(void);
     	TACHENUMBER activeTache();     	
};


#endif
