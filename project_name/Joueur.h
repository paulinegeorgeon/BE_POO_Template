/*********************************************************************
 * @file  Joueur.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Classe d'un joueur 
 *********************************************************************/

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include "Arduino.h"
#include "string.h"

/**
  * @class Joueur
  * @brief Classe Joueur
*/    

class Joueur
{
  private :

  /**
    * @fn String Role;
    * @brief Rôle du joueur
  */   
  String Role; 

  /**
    * @fn int nbGorgees;
    * @brief Nombre de gorgées du joueur
  */   
  int nbGorgees;

  /**
    * @fn bool estmort;
    * @brief Est ce que le joueur est mort
  */   
  bool estmort; 

  /**
    * @fn bool estImmunise;
    * @brief Est ce que le joueur est immunisé (que pour un tour)
  */   
  bool estImmunise;

  public :
    /**
     * @fn Joueur();
     * @brief Constructeur nul
    */    
    Joueur();
    /**
     * @fn Joueur();
     * @brief Destructeur
    */    
    ~Joueur();    

    /**
     * @fn void setRole()
     * @brief Set le rôle du joueur
    */
    void setRole(String ro);

    /**
     * @fn void getRole()
     * @brief Recupère le rôle du joueur
    */
    String getRole();

    /**
     * @fn void setNbGorgees()
     * @brief Set le nombre de gorgées du joueur 
    */
    void setNbGorgees(int Go) ;

    /**
     * @fn void getNbGorgees()
     * @brief Recupère le nombre de gorgées du joueur 
    */
    int getNbGorgees(); 

    /**
     * @fn void setEstMort()
     * @brief Definit si le joueur est mort ou non  
    */   
    void setEstMort(bool EstMort);

    /**
     * @fn void getEstMort()
     * @brief Recupere si le joueur est mort ou non  
    */ 
    bool getEstMort();

    /**
     * @fn void setImmunise()
     * @brief Set l'immunité au joueur  
    */ 
    void setImmunise(bool EstImm);

    /**
     * @fn void getImmunise()
     * @brief Recupere si le joueur est immunisé ou non   
    */ 
    bool getImmunise();
};
#endif