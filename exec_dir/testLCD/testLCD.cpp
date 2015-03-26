#include <avr/io.h>
#include "lcd.h"
#include "utility.h"

#define F_CPU 8000000UL
#define  lcdPortDirection DDRC
#define  lcdPort PORTC

//--------------------------------L'objet LCD------------------------------//
#ifndef DIPLAY_VAR
#define DIPLAY_VAR
       LCM disp(&(lcdPortDirection), &(lcdPort));
#endif

//----------------------Menu de selection des taches---------------------//
Menu mainMenu(&disp); //on fournir en paramtre la lcd

//---------------Variable qui representera la tache selectronner--------//
volatile uint8_t selectedActionIndex ;


ISR (INT0_vect)
{
      mainMenu.changeState();   
      EIFR = (1 << INTF0) ; 
}

ISR (INT1_vect)
{
        selectedActionIndex = mainMenu.validation();
        EIFR = (1 << INTF0);
}
int main()
{
       //----------------Configuration du Microcontrolleur------------//
       //  L'objet microControlleur ici, sera utiliser tout au long   //
       //  de l'application du parametre le microcontrolleur          //
       //-------------------------------------------------------------//        
       Utility microControlleur;
       microControlleur.initialisationInterruption();
       while(true)
       {
       }
        return 0;
}
