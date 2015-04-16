#include "utility.h"


void Utility::initialisationInterruption( void ) {

        // cli est une routine qui bloque toutes les interruptions.
        // Il serait bien mauvais d'etre interrompu alors que
        // le microcontroleur n'est pas pret...
        cli ();
        //'modifier ici'
        // cette procédure ajuste le registre EIMSK
        // de ATmega324PA pour permettre les interruptions externes
       EIMSK |= 1 << INT0;
       EIMSK |= 1 << INT1;
        // il faut sensibiliser les interruptions externes aux
        // changements de niveau du bouton-poussoir
        // en ajustant le registre EICRA
        EICRA |= (1 << ISC00);
        // sei permet de recevoir a nouveau des interruptions.
        sei ();
}


void Utility::initialisationUSART ( void ) 
{
	// 2400 bauds. Nous vous donnons la valeur des deux
	// premier registres pour vous éviter des complications
	UBRR0H = 0;
	UBRR0L = 0xCF;
	// permettre la reception et la transmission par le UART0
	//UCSR0A =  ;
	// Set frame format to 8 data bits, no parity, 1 stop bit
        UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
        //enable transmission and reception
        UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
}

// De l'USART vers le PC
void Utility::transmissionUSART ( uint8_t donnee ) {
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = donnee;
}

unsigned char Utility::usart_receive( void )
{
  unsigned char data;
  while ((UCSR0A & 0x80) == 0x00); // Wait for till the data arrives data
  data=UDR0;	// Read the data from UDR, as soon as the data arrives
  return data;
}



bool Utility::button1IsPressed()
{
    if (bouton1PIN & bouton1ClearValue)
    {
      _delay_ms(debounceTime);
      if(bouton1PIN & bouton1ClearValue)
       {
          return true;
       }
    }
    return false;
}


bool Utility::button2IsPressed()
{
    if (bouton2PIN & bouton2ClearValue)
    {
      _delay_ms(debounceTime);
      if(bouton2PIN & bouton2ClearValue)
       {
          return true;
       }
    }
    return false;
}

// Permet de creer un délai de durée précise de plus de 30ms en loopant _delay_ms().
void Utility::delay(uint16_t ms) {
  for (uint16_t i = 0 ; i < ms ; i++) {
    _delay_ms(1);
  }
}


uint8_t Utility::selectionTache(MENU *m)
{
	while(button2IsPressed())
	{
		if(!button1IsPressed())
		{
			while(!button1IsPressed());
			m->changeState();
		}
	}
	while(!button2IsPressed());
	return m->activeTache();
}



