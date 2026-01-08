#include <iostream> 
#include "string.h"
#include "math.h"

/*********************************************************************
 * @file  Ecran_LED.h
 * @author Emma/Raksika/Pauline
 * @brief Fichier Ecran_LED hérite de Actionneurs
 *********************************************************************/
 
#ifndef ECRAN_LCD_H
#define ECRAN_LCD_H


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
    Ecran_LED() : Actionneurs(0) {};

    /**
     * @fn ~Ecran_LED();
     * @brief Destructeur 
    */   
    ~Ecran_LED();

    /**
     * @fn void init()
     * @brief Fonction d'initialisation de l'ecran
    */

    void initialiser() {}; 

    /**
     * @fn void Afficher_message()
     * @brief Fonction d'affichage sur l'écran 
    */   
    void Afficher_message() {}; 

        /**
     * @fn void eteindre()
     * @brief Fonction d'extinction de l'actionneur
    */
    void eteindre();
}
#endif