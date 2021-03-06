#ifndef TACHE_H
#define TACHE_H

#include <avr/io.h>
#include "lcm_so1602dtr_m.h"
#include "customprocs.h"
#include "lcm_so1602dtr_m_fw.h"
#include "Sound.h"
#include "SFR05.h"
#include "utility.h"
#include "captor.h"
#include "moteur.h"
#include "Photoresistance.h"
#include "Ports.h"


// Ici nous avons les trois taches que le robot devra executer

class Tache1 {
 private:
    LCM *display;
 public:
    Tache1(LCM* d);
    void run();
};


class Tache2 {
  private:
    LCM *display;
    Captor captor;
    Moteur moteur;
  public:
    Tache2(LCM* d);
    void run();
    void suivreLigne(uint16_t duree, bool arreterSiVide = true);
    void attendreFinTournant();
};


class Tache3 {
  private:
    LCM *display;
  public:
    Tache3(LCM* d);
    void run();
};

#endif
