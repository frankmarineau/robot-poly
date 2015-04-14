#ifndef UTILITY_H
#define UTILITY_H

#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Menu.h"

#define bouton1PIN PINB
#define bouton1ClearValue 0x01
#define bouton2PIN PINB
#define bouton2ClearValue 0x02
#define debounceTime 10

class Utility
{
private:

public:
   void initialisationInterruption(void); 
   void ajustementTimer3(void);
   bool button1IsPressed();
   bool button2IsPressed();
   void initialisationUSART (void);
   void transmissionUSART (uint8_t donnee);
   void USART_Flush(void);
   uint8_t selectionTache(MENU *m);
   unsigned char usart_receive(void);
   

   static void delay(uint16_t ms); // Précise une intervale de temps donnée
   void ajustementTimer2(uint8_t vitesseA, uint8_t vitesseB, uint8_t direction);
   
};




#endif
