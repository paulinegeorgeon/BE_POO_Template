/*********************************************************************
 * @file  Bouton_tactile.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe bouton tactile qui hérite de capteurs
 *********************************************************************/

#ifndef BOUTON_TACTILE_H_
#define BOUTON_TACTILE_H_

#include "Capteurs.h"

/**
  * @class Bouton_tactile
  * @brief Bouton tactile 
*/    
class Bouton_tactile : public Capteurs{

  protected : 
  
    /**
     * @fn sensorValue
     * @brief valeur du capteur (0 ou 1)
    */ 
    int sensorValue; 


  public :

    /**
     * @fn Bouton_tactile(int p)
     * @brief constructeur avec le pin associé au bouton tactile
    */ 
    Bouton_tactile(int p);

    /**
     * @fn getValue()
     * @brief fonction qui renvoie la valeur du capteur
    */ 
    int getValue(); 

    /**
     * @fn intialiser()
     * @brief initialise le bouton tactile 
    */ 
    void initialiser(); 

}; 
#endif