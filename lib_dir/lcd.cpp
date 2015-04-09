#include "lcd.h"



Menu::Menu(LCM *disp)
{
       menuState = mode1;
       display = disp;
       afficherMenu();        
}

Menu::~Menu()
{

}

void Menu::changeState(void)
{
        switch(menuState)
        {
                case mode1:
                        {       
                                menuState = mode2;
                                break;
                        }
                case mode2:
                        {
                                menuState = mode3;
                                break;
                        }
                case mode3:
                        {
                                menuState = mode4;
                                break;
                        }
                case mode4:
                        {
                                menuState = mode5;
                                break;
                        }
                case mode5:
                        {
                                menuState = mode6;
                                break;
                        }
                case mode6:
                        {
                                menuState = mode1;
                                break;    
                        }
        }  
        afficherMenu();
}

void Menu::afficherMenu(void)
{
	
        
        display->clear();
        switch(menuState)
        {
             case mode1:
             case mode2:
                   {
                           display->write("Mode 1");
                           break;
                   }
             case mode3:
             case mode4:
                   {
                           display->write("Mode 2");
                           break;
                   }
             case mode5:
             case mode6:
                   {
                            display->write("Mode 3");
                            break;
                   }
        }
}

uint8_t Menu::validation(void)
{
	display->clear();
        switch(menuState)
        {
             case mode1:
             case mode2:
                   {
                   	   
                   	   display->write("Tache 1");
                           return 1;
                           break;
                   }
             case mode3:
             case mode4:
                   {
                   	   display->write("Tache 2");
                           return 2;
                           break;
                   }
             case mode5:
             case mode6:
                   {
                   	    display->write("Tache 3");
                            return 3;
                            break;
                   }
        }
        return 0;
        
}
