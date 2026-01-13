/*********************************************************************
 * @file  Nuit.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe Nuit qui prévoit le déroulement d'une nuit de jeu
 *********************************************************************/

#ifndef NUIT_H
#define NUIT_H

#include <Arduino.h>
#include "Jeu.h"
#include "Ecran_LED.h"
#include "Actionneurs.h" 
#include "sonMP3.h" 
#include "Bouton_tactile_I2C.h"

/**
  * @class Nuit 
  * @brief Nuit 
*/    
class Nuit {
  private:

    Jeu& jeuRef;
    Ecran_LED& ecranRef;
    SONMP3& sonRef;
    int cntGratteurs;
    Bouton_tactile_I2C& bouton; 

    // Sous-fonctions pour chaque rôle (pour ne pas avoir un code géant)
    void tourBarman();
    void tourGratteur();
    void tourEthylotest();
    void tourMaladroit();
    void tourCDV();

  public:
    // Constructeur qui prend les objets existants
    Nuit(Jeu& jeu, Ecran_LED& ecran, SONMP3& son, Bouton_tactile_I2C& bouton);

    // La fonction principale qui lance toute la séquence
    void lancerLaNuit();
};

#endif