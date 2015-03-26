


#include "lcd.h"


Menu::Menu(LCM *display)
{
       menuState = mode1;
       disp =  display;
       afficherMenu();        
}


Menu::~Menu()
{

}

void Menu::changeState()
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

void Menu::afficherMenu()
{
        
        disp->clear();
        switch(menuState)
        {
             case mode1:
             case mode2:
                   {
                           disp->write("Mode 1");
                           break;
                   }
             case mode3:
             case mode4:
                   {
                           disp->write("Mode 2");
                           break;
                   }
             case mode5:
             case mode6:
                   {
                            disp->write("Mode 3");
                            break;
                   }
        }
}

uint8_t Menu::validation()
{
        switch(menuState)
        {
             case mode1:
             case mode2:
                   {
                           return 1;
                           break;
                   }
             case mode3:
             case mode4:
                   {
                           return 2;
                           break;
                   }
             case mode5:
             case mode6:
                   {
                            return 3;
                            break;
                   }
        }
        
}
