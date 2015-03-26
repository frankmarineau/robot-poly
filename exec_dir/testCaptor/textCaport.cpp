#include <avr/io.h>
#include "captor.h"
#include "utility.h"

#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"


#define  lcdPortDirection DDRC
#define  lcdPort PORTC

int main()
{
        LCM disp(&(lcdPortDirection), &(lcdPort));
        Utility microController;
        microController.initialisationUSART();
        Captor c;
        while(true)
        {
               microController.transmissionUSART(c.read());
              //disp.put(char(c.read()));
               
        }
        return 0;
}
