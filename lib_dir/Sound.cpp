#include "Sound.h"

void Sound::jouerSound() {
  TCCR0A |= (1<<WGM01)|(1<<COM0A0);     // CTC mode, toggle OC0 on compare match
  TCCR0B |= (1<<CS02);                   // Start timer0 with prescaler 256
  OCR0A = 10;
}

void Sound::arreterSound() {
  TCCR0B &= 0x00;
}