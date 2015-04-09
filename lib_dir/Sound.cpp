#include "Sound.h"


void Sound::jouerSound(float frequence){
        
        float periode = (1/2*frequence);
	float activeTime = periode*1000000; //*8 000 000/8 (prescaler)
	TCCR0A|=(1<<COM0A0); //Toggle OC0A on Compare Match
	TCCR0A|=(1<<WGM01); //CTC mode
	TCCR0B|=(1<<CS01); //Prescaler de 8
	TCNT0 = 0x00; //Counter fixed at 0
	OCR0A = activeTime; //valeur de comparaison fixee a activeTime


}
     
void Sound::arreterSound() {

        TCCR0A &= 0x00;// Deconnection de 0C0A
	TCCR0A|=(1<<WGM01); // CTC mode
	TCCR0B|=(1<<CS01); // Prescaler de 8
	TCNT0=0x00;//Counter=0
}
    

