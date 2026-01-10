/*********************************************************************
 * @file  Bouton_tactile_I2C.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe bouton tactile I2C qui hérite de capteurs
 *********************************************************************/

#ifndef BOUTON_TACTILE_I2C_H_
#define BOUTON_TACTILE_I2C_H_

#include "Capteurs.h"
#include <Arduino.h>
#include <Wire.h>

/**
  * @class Bouton_tactile
  * @brief Bouton tactile 
*/    
class Bouton_tactile_I2C : public Capteurs{

  protected : 
  
    /**
     * @fn sensorValue
     * @brief numéro du capteur codé sur 8 bits chaque bit correspondant à chaque capteur
    */ 
  
    uint8_t Num_Capteur; 


  public :

    /**
     * @fn Bouton_tactile(uint8_t num_bouton)
     * @brief constructeur avec le pin associé au bouton tactile
    */ 
    Bouton_tactile_I2C(uint8_t num_bouton);

    /**
     * @fn getValue()
     * @brief fonction qui renvoie la valeur du capteur
    */ 
    int getValue(); 

    /**
     * @fn intialiser()
     * @brief initialise l'I2C touch sensor besoin de le faire une seule fois pour tous les boutons
    */ 
    void initialiser(); 

}; 
#endif