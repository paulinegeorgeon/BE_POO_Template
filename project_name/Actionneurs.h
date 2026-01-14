/*********************************************************************
 * @file  Actionneurs.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier Actionneurs hérite de Périphériques
 *********************************************************************/

#ifndef ACTIONNEURS_H_
#define ACTIONNEURS_H_

#include "Peripheriques.h"

/**
  * @class Actionneurs
  * @brief Classe Actionneurs
*/  
class Actionneurs : public Peripheriques
{
  protected : 

  public : 
    /**
     * @fn Actionnneurs();
     * @brief Constructeur par defaut
    */    
    Actionneurs(int p);

    /**
     * @fn ~Actionneurs();
     * @brief Destructeur 
    */    
    ~Actionneurs();


    /**
     * @fn void eteindre()
     * @brief Fonction d'extinction de l'actionneur
    */
    virtual void eteindre() =0;
};
#endif