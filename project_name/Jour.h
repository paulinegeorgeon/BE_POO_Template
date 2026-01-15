/*********************************************************************
 * @file  Jour.h
 * @author Emma,Raksika,Pauline
 * @brief Deroulement du jeu partie JOUR
 *********************************************************************/
#ifndef JOUR_H_
#define JOUR_H_

#include <iostream> 
#include "Arduino.h"
#include "string.h"
#include "Jeu.h"
#include "Ecran_LED.h"
#include "sonMP3.h"
#include "Bouton_tactile_I2C.h"

using namespace std;

/**
  * @class Jour
  * @brief Classe Jour
*/    

class Jour
{
  private :

    /**
      * @fn Jeu& jeuRef;
      * @brief récupère un jeu
    */   
    Jeu& jeuRef;
    /**
      * @fn  Ecran_LED& ecranRef;
      * @brief récupère un écran
    */           /**
      * @fn  Bouton_tactile_I2C& bouton;
      * @brief récupère un bouton
    */  
    Ecran_LED& ecranRef;

    /**
      * @fn  SONMP3& sonRef;
      * @brief récupère un son
    */        
    SONMP3& sonRef;

    /**
      * @fn  Bouton_tactile_I2C& bouton;
      * @brief récupère un bouton
    */  
    Bouton_tactile_I2C bouton;

    /**
     * @fn EstMort();
     * @brief Définit si le Joueur est mort ou non, pour sauter ou non son tour 
    */    
    void EstMort();

    /**
     * @fn RecapGorgees();
     * @brief Permet de faire un recap joueur par joueur du nombre de gorgées restantes
    */    
    void RecapGorgees();

    /**
     * @fn PartieFinie
     * @brief Booléen pour savoir si la partie est finie ou non
    */ 
    bool PartieFinie;
    

  public :
  
      /**
     * @fn Jour();
     * @brief Destructeur
    */    
    ~Jour();

    /**
    * @fn   Jour(Jeu& jeu, Ecran_LED& ecran, SONMP3& son, Bouton_tactile_I2C&  bouton);
    * @brief Constructeur qui prend les objets existants
    */   
    Jour(Jeu& jeu, Ecran_LED& ecran, SONMP3& son, Bouton_tactile_I2C& bouton);
    /**
     * @fn lancerLeJour();
     * @brief Partie du jour
    */    
    void lancerLeJour();

    /**
     * @fn QuiGagne();
     * @brief Renvoie 1 si les villageois gagnent,2 si les gratteurs gagnent, 0 sinon
    */    
    int QuiGagne();

    /**
     * @fn getPartieFinie();
     * @brief Renvoie si la partie est finie ou non
    */    
    bool getPartieFinie ();

    /**
     * @fn QuiGagne();
     * @brief Definit si la partie est finie ou non
    */    
    void setPartieFinie(bool resu);
};
#endif