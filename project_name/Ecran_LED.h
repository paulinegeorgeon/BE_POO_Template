/*********************************************************************
 * @file  Ecran_LED.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier Ecran_LED hérite de Actionneurs
 *********************************************************************/

#include <Arduino.h> 
#include "string.h"

#ifndef ECRAN_LED_H
#define ECRAN_LED_H

#include <rgb_lcd.h>
#include "Actionneurs.h"

/**
  * @class Ecran_LED
  * @brief Classe Ecran_LED
*/  

class Ecran_LED : public Actionneurs
{
  protected : 

    /**
     * @fn rgb_lcd lcd;
     * @brief Objet interne pour piloter le matériel  
    */ 
    rgb_lcd lcd;

  public : 
    /**
     * @fn Ecran_LED();
     * @brief Constructeur par defaut
    */    
    Ecran_LED();

    /**
     * @fn ~Ecran_LED();
     * @brief Destructeur 
    */   
    ~Ecran_LED();

    /**
     * @fn void Afficher_message()
     * @brief Fonction d'affichage sur l'écran 
    */   
    void Afficher_message(String ligne1, String ligne2); 

    /**
     * @fn void eteindre()
     * @brief Fonction d'extinction de l'actionneur
    */
    void eteindre();

    /**
     * @fn void eteindre()
     * @brief Fonction d'initialisation de l'écran LCD
    */
    void initialiser();
};
#endif