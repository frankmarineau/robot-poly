#ifndef UTILITY_H
#define UTILITY_H

#include "setting.h"
#include "Menu.h"



class Utility
{
private:

public:
   static void initialisationInterruption(void); 
   static void ajustementTimer3(void);
   static bool button1IsPressed();
   static bool button2IsPressed();
   static void initialisationUSART (void);
   static void transmissionUSART (uint8_t donnee);
   static void USART_Flush(void);
   static uint8_t selectionTache(MENU *m);
   static unsigned char usart_receive(void);
   static void delay(uint16_t ms); // Précise une intervale de temps donnée
   static void ajustementTimer2(uint8_t vitesseA, uint8_t vitesseB, uint8_t direction);
   
};




#endif
