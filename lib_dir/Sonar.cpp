#include "Sonar.h"


     
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

