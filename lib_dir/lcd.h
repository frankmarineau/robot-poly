
/*********************************************************************/
/*       PROJET INTEGRATEUR 1ERE ANNEE -- HIVER 2015                 */
/*********************************************************************/
/* Ecrit par : Foromo Daniel Soromou , le 25 Mars 2015               */
/* A l'Ecole Polytechnique de Montreal                               */
/*********************************************************************/
/* Description : Cette parite du projet, est l'interaction entre le  */
/*               le robot "Charlie" et l'utilisateur. L'epreuve etant*/
/*               constituer de 3 parties (modes), l'utilisateur      */    
/*               devra, a l'aide des 2 boutons pousoir sur la        */
/*               breadboad, selectionner et valider le mode de son   */
/*               choix.                                              */
/*********************************************************************/


#ifndef LCD_H
#define LCD_H

#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"
#include <stdlib.h>
#include <avr/io.h>


//---------------Les differents de notre menu -----------------------//
enum state {mode1, mode2, mode3, mode4, mode5 , mode6}; 


class Menu
{
private:
        state menuState;
        LCM *display;
        void afficherMenu(void);
        
public:
        Menu(LCM *d);
        ~Menu();
        void changeState(void);
       
        uint8_t validation(void);
};



#endif
