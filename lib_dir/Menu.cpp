#include "Menu.h"

void MENU::afficherMenu(void)
{
  display->clear();
  switch(menuState)
  {
    case MODE1: display->write("Mode 1"); break;
    case MODE2: display->write("Mode 2"); break;
    case MODE3: display->write("Mode 3"); break;
  }
}

MENU::MENU(LCM *disp)
{
  menuState = MODE1;
  display = disp;
  afficherMenu();
}

void MENU::changeState(void)
{
  switch(menuState)
  {
    case MODE1: menuState = MODE2; break;
    case MODE2: menuState = MODE3; break;
    case MODE3: menuState = MODE1; break;
  }
  afficherMenu();
}

TACHENUMBER MENU::activeTache()
{
  switch(menuState)
  {
  	case MODE1: display->write("Tache 1"); return T1;
  	case MODE2: display->write("Tache 2"); return T2;
  	case MODE3: display->write("Tache 3"); return T3;
  }
}