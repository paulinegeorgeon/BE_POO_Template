#include <iostream> 
#include "string.h"
#include "math.h"
using namespace std;


/*********************************************************************
 * @file  Actionneurs.h
 * @author Emma/Raksika/Pauline
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
    Actionneurs(int p) : Peripheriques(p) {}

    /**
     * @fn ~Actionneurs();
     * @brief Destructeur 
    */    
    ~Actionneurs();

    /**
     * @fn void init()
     * @brief Fonction d'initialisation de l'actionneur
    */
    virtual void initialiser() =0;

    /**
     * @fn void eteindre()
     * @brief Fonction d'extinction de l'actionneur
    */
    virtual void eteindre() =0;
}
#endif