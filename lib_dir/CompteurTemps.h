#ifndef COMPTEUR_TEMPS_H
#define COMPTEUR_TEMPS_H


class Compteur
{
  private:
        uint8_t temps;
  public:
         Compteur();
         Compteur(uint8_t t);
        ~Compteur();
       
        //setPosition(LIGNE newPosition);
        void run();
        
};
