#ifndef UTILITY_H
#define UTILITY_H

#include "setting.h"
#include "Menu.h"



class Utility
{
private:

public:
   static void initialisationInterruption(void);  //Initialisation des interruption INT0 et INT1
   static bool button1IsPressed(); //Verfication du boutton 1
   static bool button2IsPressed(); //Verification du boutton 2
   static void initialisationUSART (void); //Initialisation de L'USART
   static void transmissionUSART (uint8_t donnee); //Transmission des informations via L'USAR
   static uint8_t selectionTache(MENU *m);
   static unsigned char usart_receive(void);
   static void delay(uint16_t ms); // Précise une intervale de temps donnée
   static void ajustementTimer2(uint8_t vitesseA, uint8_t vitesseB, uint8_t direction); //Ajustement Timer2
   
};




#endif
