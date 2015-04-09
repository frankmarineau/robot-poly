#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "lcd.h"
#include "utility.h"
#include "Tache.h"

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
     // EIFR = (1 << INTF0) ; 
}

ISR (INT1_vect)
{
        selectedActionIndex = mainMenu->validation();
        
        EIFR = (1 << INTF1);
   
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
       
       while(selectedActionIndex ==0);
       
       //Tache *tableauTache[3] = {(Tache1 *)malloc(sizeof(Tache1)), (Tache2 *)malloc(sizeof(Tache2)),(Tache3 *)malloc(sizeof(Tache3))};
       
       Tache1 t1;
       Tache2 t2;
       Tache3 t3;

       switch(selectedActionIndex)
       {
       	case 1: t1.run(); break;
       	case 2: t2.run(); break;
       	case 3: t3.run(); break;
       }
      
      
      
    
      
       
      // while(true);
      
       
        return 0;
}


