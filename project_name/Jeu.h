/*********************************************************************
 * @file  Jeu.h
 * @author Emma,Raksika,Pauline
 * @brief Descrpition des règles du jeu 
 *********************************************************************/

#ifndef JEU_H_
#define JEU_H_

#include <iostream> 
#include "Arduino.h"
#include "string.h"
using namespace std;

class Jeu : public Joueur {
  private : 

  Joueur Joueurs[6]{Joueur1,Joueur2,Joueur3,Joueur4,Joueur5,Joueur6};

  public: 
      /**
     * @fn Jeu();
     * @brief Constructeur par defaut
    */    
  Jeu(); 
    /**
     * @fn Joueur();
     * @brief Destructeur par defaut
    */    
  ~Jeu();

    /**
     * @fn RepartitionRoles();
     * @brief Pour chaque joueur, donne son rôle et initialise le nb gorgees
    */    
  void RepartitionRoles () {};
  

}