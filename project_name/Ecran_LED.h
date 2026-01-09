#include <Arduino.h> 
#include "string.h"
#include "math.h"

/*********************************************************************
 * @file  Ecran_LED.h
 * @author Emma/Raksika/Pauline
 * @brief Fichier Ecran_LED hérite de Actionneurs
 *********************************************************************/
 
#ifndef ECRAN_LED_H
#define ECRAN_LED_H


#include <rgb_lcd.h>
#include "Actionneurs.h"
using namespace std;


/**
  * @class Ecran_LED
  * @brief Classe Ecran_LED
*/  

class Ecran_LED : public Actionneurs
{
  protected : 

    rgb_lcd lcd; // Objet interne pour piloter le matériel 

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
    void initialiser();
};
#endif