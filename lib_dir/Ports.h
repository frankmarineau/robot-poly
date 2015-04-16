#ifndef PORTS_H
#define PORTS_H

#include "setting.h"
#include "can.h"

class Ports {
public:
	static void initialiserPorts(volatile uint8_t *, volatile uint8_t *, volatile uint8_t *, volatile uint8_t *);

	//Input
	static uint8_t lireSonar();
	static uint8_t lirePhotoresistanceGauche();
	static uint8_t lirePhotoresistanceDroite();
	static uint8_t lireCapteur();
	static uint8_t lireBoutonSelection();
	static uint8_t lireBoutonConfirmation();

	//Output
	static void setDirectionMoteur(uint8_t val);
	static void setSon(uint8_t val);
	static void setSonar(uint8_t val);
};

#endif
