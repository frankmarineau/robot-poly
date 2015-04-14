#ifndef UTILITY_H
#define UTILITY_H

#include "setting.h"
#include "Menu.h"


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
