/*********************************************************************
 * @file  MP3.h
 * @author Pauline, Emma, Raksika
 * @brief hérite de Actionneurs.h
 *********************************************************************/
 
 
#ifndef MP3_H
#define MP3_H

#include "SeeedGroveMP3.h"
#include "KT403A_Player.h"
#include "Actionneurs.h"
//#include <Arduino.h>
#include <SoftwareSerial.h>
//#include <Seeed_Serial_MP3_Player.h>


/**
  * @class MP3
  * @brief Classe Application 
*/   

class MP3 : public Actionneurs{
private:
    SoftwareSerial* _mp3Serial; // Pointeur pour gérer la liaison série logicielle
    uint8_t _rxPin;
    uint8_t _txPin;
    KT403A<SoftwareSerial> _player;

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
    void initialiser(uint8_t defaultVolume = 20);

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

                               
};

#endif