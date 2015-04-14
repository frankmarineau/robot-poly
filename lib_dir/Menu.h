#ifndef MENU_H
#define MENU_H

#include "setting.h"

enum TACHENUMBER {T1, T2, T3};           //Litteral pour identifier les differentes taches        //
enum MODE {MODE1,MODE2, MODE3};         //Litteral pour identifer les differentes modes           //

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
