#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "Menu.h"
#include "utility.h"
#include "Tache.h"
#include "Ports.h"

#define F_CPU 8000000UL
#include <util/delay.h>
#define  lcdPortDirection DDRC
#define  lcdPort PORTC

//---------------Variable qui representera la tache selectronner--------//
volatile uint8_t selectedActionIndex=0 ;


int main()
{
	
       //----------------Configuration du Microcontrolleur------------//
       //  L'objet microControlleur ici, sera utiliser tout au long   //
       //  de l'application du parametre le microcontrolleur          //
       //-------------------------------------------------------------//      
       LCM disp(&(lcdPortDirection), &(lcdPort)); 
       MENU tmpMenu(&disp); 
     
      
    
       Ports::initialiserPorts(&DDRA,&DDRB,&DDRC,&DDRD);
       
       Utility microControlleur;
       selectedActionIndex =microControlleur.selectionTache(&tmpMenu);
       
       Tache1 t1(&disp);
       Tache2 t2(&disp);
       Tache3 t3(&disp);

       switch(selectedActionIndex)
       {
       	case T1: t1.run(); break;
       	case T2: t2.run(); break;
       	case T3: t3.run(); break;
       }       
      
       
        return 0;
}




