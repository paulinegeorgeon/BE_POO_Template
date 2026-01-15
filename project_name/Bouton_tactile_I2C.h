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
#include <i2c_touch_sensor.h>

/**
  * @class Bouton_tactile
  * @brief Bouton tactile 
*/    
class Bouton_tactile_I2C : public Capteurs{

  protected : 
  
    /**
     * @fn uint8_t Num_Capteur
     * @brief numéro du capteur codé sur 8 bits chaque bit correspondant à chaque capteur
    */ 
    uint8_t Num_Capteur; Bouton

  public :

    /**
     * @fn Bouton_tactile()
     * @brief constructeur nul
    */ 
    Bouton_tactile_I2C();

    /**
     * @fn ~Bouton_tactile_I2C()
     * @brief destructeur
    */ 
    ~Bouton_tactile_I2C();
    
    /**
     * @fn intialiser()
     * @brief initialise l'I2C touch sensor besoin de le faire une seule fois pour tous les boutons
    */ 
    void initialiser(); 

    /**
     * @fn joueurAppuye()
     * @brief fonction qui le numéro du capteur appuyé
    */ 
    int joueurAppuye(); 
}; 
#endif