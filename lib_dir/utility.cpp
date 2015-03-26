#include "utility.h"


void Utility::initialisationInterruption( void ) {

        // cli est une routine qui bloque toutes les interruptions.
        // Il serait bien mauvais d'etre interrompu alors que
        // le microcontroleur n'est pas pret...
        cli ();
        //'modifier ici'
        // cette procédure ajuste le registre EIMSK
        // de ATmega324PA pour permettre les interruptions externes
       EIMSK |= _BV(INT0);
        // il faut sensibiliser les interruptions externes aux
        // changements de niveau du bouton-poussoir
        // en ajustant le registre EICRA
        EICRA |= (1 << ISC00);
        // sei permet de recevoir a nouveau des interruptions.
        sei ();
}

bool Utility::button1IsPressed()
{
    if (!(bouton1PIN & bouton1ClearValue))
    {
      _delay_ms(debounceTime);
      if(!(bouton1PIN & bouton1ClearValue))
       {
          return true;
       }
    }
    return false;
}


bool Utility::button2IsPressed()
{
    if (!(bouton2PIN & bouton2ClearValue))
    {
      _delay_ms(debounceTime);
      if(!(bouton2PIN & bouton2ClearValue))
       {
          return true;
       }
    }
    return false;
}
