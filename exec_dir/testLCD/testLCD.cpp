#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "utility.h"

#define F_CPU 8000000UL
#define  lcdPortDirection DDRC
#define  lcdPort PORTC


       
//----------------------Menu de selection des taches---------------------//
//static Menu mainMenu; //on fournir en paramtre la lcd

//---------------Variable qui representera la tache selectronner--------//
volatile uint8_t selectedActionIndex=0 ;



Menu *mainMenu;

ISR (INT0_vect)
{
      mainMenu->changeState();
      EIFR = (1 << INTF0) ; 
}

ISR (INT1_vect)
{
        selectedActionIndex = mainMenu->validation();
        EIFR = (1 << INTF0);
}

int main()
{
       //----------------Configuration du Microcontrolleur------------//
       //  L'objet microControlleur ici, sera utiliser tout au long   //
       //  de l'application du parametre le microcontrolleur          //
       //-------------------------------------------------------------//      
       LCM disp(&(lcdPortDirection), &(lcdPort)); 
       Menu tmpMenu(&disp); 
       mainMenu =&tmpMenu;
      
       Utility microControlleur;
       microControlleur.initialisationInterruption();
       while(true)
       {
       }
        return 0;
}


