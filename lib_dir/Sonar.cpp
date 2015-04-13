#include "Sonar.h"

#include "Sonar.h"


     
void initialisationTimer(void)
{
	PORTA = ( 1<<PORTA0 );		// Send trigger pin high
	
	startTimer(0x0001);		// Wait around 10 uS before sending it low again 
	
	waitForTimer();
	
	PORTA = ( 0<<PORTA0 );
	
}

unsigned int getEcho(void)
{
unsigned int range;
 
	while(!(PINA&0x02));	  // Wait for echo pin to go high,  this indicates the start of the incoming pulse
	TCNT1 = 0x00; 		 // Clear timer to zero
	TCCR1B = START_CLK_N;	// Start timer running 1:8 prescaler in normal mod
	while((PINA&0x02));	// Wait for echo pin to go low signaling that the pulse has ended
	
	TCCR1B = STOP_CLK;	// Stop the timer and set back to CTC mode	
	range = TCNT1/58;	// Read back value in the timer counter register, this number divided by 58 will give us the range in CM
	
	return(range);
}

void startTimer(unsigned int time)
{
	OCR1A = time;			// Time set to count to
	TIFR1 = 0x02;			// Clear timer campare match flag
	TCNT1 = 0x00; 			// Clear timer to zero
	TCCR1B = START_CLK;		// Start timer running 1:8 prescaler
}

void waitForTimer(void)
{
	while(!(TIFR1&0x02));	// wait for timer to set compare match flag
	TCCR1B = STOP_CLK;		// Stop the timer
}

void setup(void)
{
	DDRA = 0x01;			// Port A pin 0 ouput all others input

	TCCR1A = 0x04;			// Set timer up in CTC mode
	TCCR1B = 0x08;	
	
}
