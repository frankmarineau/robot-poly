#ifndef PORTS_Hvolatile uint8_t *port
#define PORTS_H

class Ports {
public:
	static void initialiserPorts();

	//Input
	static uint8_t lireSonar();
	static uint8_t lirePhotoresistance();
	static uint8_t lireCapteur();
	static uint8_t lireBoutonSelection();
	static uint8_t lireBoutonConfirmation();

	//Output
	static void setDirectionMoteur(uint8_t val);
	static void setSon(uint8_t val);
	static void setSonar(uint8_t val);
};

#endif
