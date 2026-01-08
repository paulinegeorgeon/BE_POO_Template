/*********************************************************************
 * @file  MP3.h
 * @author Pauline, Emma, Raksika
 * @brief hérite de Actionneurs.h
 *********************************************************************/
 
 
#ifndef MP3_H
#define MP3_H

#include "Actionneurs.h"
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <MP3Player_KT403A.h>


/**
  * @class MP3
  * @brief Classe Application 
*/   

class MP3 {
private:
    SoftwareSerial* _mp3Serial; // Pointeur pour gérer la liaison série logicielle
    uint8_t _rxPin;
    uint8_t _txPin;

public:
    /**
     * @fn MP3();
     * @brief Constructeur par defaut
    */ 
    MP3(uint8_t rxPin, uint8_t txPin);
    
    /**
     * @fn ~MP3();
     * @brief Destructeur
    */ 
    ~MP3();

    /**
     * @fn void init(uint8_t defaultVolume)
     * @brief Fonction d'initialisation de l'application (à appeler dans le setup)
    */ 
    void init(uint8_t defaultVolume = 20);

    /**
     * @fn void playAudio(uint8_t folder, uint8_t index);
     * @brief Fonction de lancement d'un son à partir d'un fichier precis index dans folder
    */
    void playAudio(uint8_t folder, uint8_t index);

    /**
     * @fn void stop();
     * @brief Fonction qui arrete l'audio
    */
    void stop(); 
    
    /**
     * @fn setVolume(uint8_t volume);
     * @brief Fonction qui modifie le volume (0-30)
    */                                  
    void setVolume(uint8_t volume);  

    /**
     * @fn next();
     * @brief Fonction qui joue la piste d'après
    */ 
    void next();                                   

    /**
     * @fn previous();
     * @brief Fonction qui joue la piste d'avant
    */ 
    void previous();                               
};

#endif