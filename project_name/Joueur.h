/*********************************************************************
 * @file  Joueur.h
 * @author Emma,Raksika,Pauline
 * @brief Fonction utiles aux joueurs
 *********************************************************************/
#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <iostream> 
#include "Arduino.h"
#include "string.h"
using namespace std;

/**
  * @class Joueur
  * @brief Classe Joueur
*/    

class Joueur
{
  private :

  String Role; 
  int nbGorgees;
  bool estmort; 

  bool estImmunise;
  public :
    /**
     * @fn Joueur();
     * @brief Constructeur par defaut
    */    
    Joueur();
    /**
     * @fn Joueur();
     * @brief Destructeur
    */    
    ~Joueur();    

    /**
     * @fn void setRole()
     * @brief Donne le rôle d'un joueur
    */
    void setRole(String ro);

        /**
     * @fn void getRole()
     * @brief Recupère le rôle 
    */
    String getRole();

      /**
     * @fn void setNbGorgees()
     * @brief Met le nombre de gorgées du joueur 
    */
    void setNbGorgees(int Go) ;

      /**
     * @fn void getNbGorgees()
     * @brief Recupère le nombre de gorgées du joueur 
    */
    int getNbGorgees(); 

      /**
     * @fn void setEstMort()
     * @brief Definit s'il est mort ou non  
    */   
    void setEstMort(bool EstMort);


          /**
     * @fn void getEstMort()
     * @brief Recupere s'il est mort ou non  
    */ 
    bool getEstMort();

    void setImmunise();
    bool getImmunise();

};
#endif