/*********************************************************************
 * @file  Jour.h
 * @author Emma,Raksika,Pauline
 * @brief Deroulement du jeu partie JOUR
 *********************************************************************/
#ifndef JOUR_H_
#define JOUR_H_

#include <iostream> 
#include "Arduino.h"
#include "string.h"
#include "Jeu.h"
#include "Ecran_LED.h"
#include "sonMP3.h"
#include "Bouton_tactile_I2C.h"

using namespace std;

/**
  * @class Jour
  * @brief Classe Jour
*/    

class Jour
{
  private :

    Jeu& jeuRef;
    Ecran_LED& ecranRef;
    SONMP3& sonRef;
    Bouton_tactile_I2C bouton;

    void EstMort();
    void RecapGorgees();
    void QuiGagne();

  public :
    /**
     * @fn Jour();
     * @brief Constructeur par defaut
    */    
    Jour(Jeu& jeu, Ecran_LED& ecran, SONMP3& son, Bouton_tactile_I2C& bouton);
    /**
    /**
     * @fn lancerLeJour();
     * @brief Partie du jour
    */    
    void lancerLeJour();

};
#endif