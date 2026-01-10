/*********************************************************************
 * @file  Capteurs.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe capteur qui hérite de périphériques
 *********************************************************************/

#ifndef CAPTEURS_H_
#define CAPTEURS_H_

#include "Peripheriques.h"


/**
  * @class Capteurs
  * @brief Classe Capteurs 
*/    
class Capteurs : public Peripheriques {
  
  public : 
      /**
     * @fn Capteurs()
     * @brief constructeur nul
    */ 
    Capteurs();

    /**
     * @fn Capteurs(int p)
     * @brief constructeur avec le pin associé au périph
    */ 
    Capteurs(int p);

    /**
     * @fn getValue()
     * @brief récupère la valeur du capteur 
    */ 
    virtual int getValue()=0;
};

#endif