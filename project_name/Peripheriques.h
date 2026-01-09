/*********************************************************************
 * @file  Peripheriques.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier header pour tous les périphs
 *********************************************************************/

#ifndef PERIPHERIQUES_H_
#define PERIPHERIQUES_H_

/**
  * @class Peripheriques
  * @brief Classe peripheriques
*/    

class Peripheriques{

  protected : 
  
     /**
     * @fn int pin;
     * @brief pin associé au périph 
    */ 
    int pin;

  public: 

    /**
     * @fn peripheriques(int p)
     * @brief constructeur avec le pin associé au périph
    */ 
    Peripheriques(int p);

    /**
     * @fn peripheriques()
     * @brief destructeur
    */ 
    ~Peripheriques();

    /**
     * @fn virtual void initiliser()
     * @brief initialisaiton du peripherique
    */ 
    virtual void initialiser()=0;
};

#endif