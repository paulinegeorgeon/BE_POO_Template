/*********************************************************************
 * @file  Jeu.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Classe de descrpition des règles du jeu 
 *********************************************************************/

#ifndef JEU_H_
#define JEU_H_

#include "Arduino.h"
#include "string.h"
#include "Joueur.h"

/**
  * @class Jeu
  * @brief Classe jeu
*/    
class Jeu {
  private : 

  /**
    * @fn String rolesDisponibles[6];
    * @brief Tableau des 6 rôles possibles
  */   
  String rolesDisponibles[6] = {
        "Maladroit", 
        "Barman", 
        "Gratteur Verre", 
        "Gratteur Verre",
        "Capote de Verre", 
        "Ethylotest"
    };

  /**
    * @fn Joueur listeJoueurs[6]
    * @brief Tableau de 6 joueurs
  */     
  Joueur listeJoueurs[6];

  public: 

  /**
    * @fn Jeu();
    * @brief Constructeur nul
  */    
  Jeu(); 
    /**
     * @fn Joueur();
     * @brief Destructeur
    */    
  ~Jeu();

  /**
    * @fn RepartitionRoles();
    * @brief Pour chaque joueur, donne son rôle et initialise le nb gorgees
  */    
  void RepartitionRoles ();
  
  /**
    * @fn Joueur* getJoueur(int index);
    * @brief Retourne le joueur n°index
  */      
  Joueur* getJoueur(int index);

  /**
    * @fn void ajouterGorgees(int index);
    * @brief Ajoute une gorgée au joueur n°index
  */   
  void ajouterGorgees(int index);

  /**
    * @fn void retirerGorgees(int index);
    * @brief Retire une gorgée au joueur n°index
  */   
  void retirerGorgees(int index);

  /**
    * @fn void immuniserJoueur(int index);
    * @brief Immunise le joueur n°index
  */   
  void immuniserJoueur(int index);

}; 
#endif