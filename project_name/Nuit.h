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

  /**
    * @fn Jeu& jeuRef;
    * @brief récupère un jeu
  */   
  Jeu& jeuRef;

  /**
    * @fn  Ecran_LED& ecranRef;
    * @brief récupère un écran
  */   
  Ecran_LED& ecranRef;

  /**
    * @fn  SONMP3& sonRef;
    * @brief récupère un son
  */    
  SONMP3& sonRef;

  /**
    * @fn  int cntGratteurs;
    * @brief Nombre de gratteur
  */      
  int cntGratteurs;

  /**
    * @fn  Bouton_tactile_I2C& bouton;
    * @brief récupère un bouton
  */      
  Bouton_tactile_I2C& bouton; 

  // Sous-fonctions pour chaque rôle

  /**
    * @fn  void tourBarman();
    * @brief fonction du tour du barman
  */      
  void tourBarman();

  /**
    * @fn  void tourGratteur();
    * @brief fonction du tour du gratteur de verre
  */      
  void tourGratteur();

  /**
    * @fn  void tourEthylotest();
    * @brief fonction du tour de l'éthylotest
  */      
  void tourEthylotest();

  /**
    * @fn  void tourMaladroit();
    * @brief fonction du tour du maladroit
  */      
  void tourMaladroit();

  /**
    * @fn  void tourProtege();
    * @brief fonction du tour du Protège verre
  */  
  void tourProtege();

  public:

  /**
  * @fn   Nuit(Jeu& jeu, Ecran_LED& ecran, SONMP3& son, Bouton_tactile_I2C& bouton);
  * @brief Constructeur qui prend les objets existants
  */ 
  Nuit(Jeu& jeu, Ecran_LED& ecran, SONMP3& son, Bouton_tactile_I2C& bouton);

  /**
  * @fn   void lancerLaNuit();
  * @brief Fonction principale qui lance toute la séquence
  */ 
  void lancerLaNuit();
};

#endif