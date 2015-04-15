#include "Sound.h"
#include "setting.h"

void Sound::jouerSound(uint16_t frequence){
     TCCR2A |= (1<<WGM21)|(1<<COM2A0) | (1 << COM2B0);     // CTC mode, toggle OC0 on compare match
     TCCR2B = (1<<CS22) | (1 << CS21) | (1 << CS20);                   // Start timer0 with prescaler 256	
     OCR2A =  F_CPU /2048/frequence;
    
}
     
void Sound::arreterSound() {
  TCCR2B &= 0x00;
}
