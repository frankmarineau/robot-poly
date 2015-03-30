#include "Sonar.h"

void Sonar::initialisationUSART(){
            

	    //2400 bauds. Nous vous donnons la valeur des deux
	    // premier registres pour vous éviter des complications
	    UBRR0H = 0;
	    UBRR0L = 0xCF;
	    //permettre la reception et la transmission par le UART0
	    //UCSR0A = ??  ;
	    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	    //Format des trames: 8 bits, 1 stop bits, none parity
	    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00)|(0<< UPM00)|(0<< UPM10)|(0 << USBS0);
}






     
void Sonar::envoiDuTrigerPulse(){
    
    //Le sonar envoi ici des ondes 
    PORTD |= (1 << 0); //Envoi du trigger pulse
    _delay_us(10);
    // Remise a zero du PORTD
    PORTD = 0x00; 
    // ici c'est juste le delai d'attente du retour de signal
    _delay_us(700); 
}
     
void Sonar::receptionDuSignal(){
        
        //variable de calcul de la longueur d'onde
        uint8_t longeurOnde = 0;
        // tant qu'il a reception d'informations
	while((PIND &= (1 << PIND1)))
        {
	  longeurOnde++;
	  PORTA=0xAA;
	}
	PORTA=0x00;

}

