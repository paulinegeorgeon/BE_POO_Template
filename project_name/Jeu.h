/*********************************************************************
 * @file  Jeu.h
 * @author Emma,Raksika,Pauline
 * @brief Descrpition des règles du jeu 
 *********************************************************************/

#ifndef JEU_H_
#define JEU_H_

#include "Arduino.h"
#include "string.h"
#include "Joueur.h"
#include "Bouton_tactile_I2C.h"


class Jeu {
  private : 
  String rolesDisponibles[6] = {
        "Maladroit", 
        "Barman", 
        "Gratteur Verre", 
        "Gratteur Verre",
        "Capote de Verre", 
        "Ethylotest"
    };

  Joueur listeJoueurs[6];

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
  void RepartitionRoles ();
  
  Joueur* getJoueur(int index);

  void ajouterGorgees(int index);
  void retirerGorgees(int index);

  void immuniserJoueur(int index);
}; 
#endif