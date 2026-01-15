/*********************************************************************
 * @file  sonMP3.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier sonMP3 hérite de Actionneurs
 *********************************************************************/
 
#ifndef SONMP3_H
#define SONMP3_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Actionneurs.h"

/**
  * @class SONMP3
  * @brief Classe SONMP3
*/  

class SONMP3 : public Actionneurs
{
  protected : 
    /**
     * @fn SoftwareSerial* _serial
     * @brief pointeur vers un objet de communication série. C'est ce qui permet de parler au module MP3 via les Pins. 
    */ 
    SoftwareSerial* _serial;

    /**
     * @fn uint8_t _rxPin
     * @brief pin de RX
    */ 
    uint8_t _rxPin;

    /**
     * @fn uint8_t _txPin
     * @brief pin de TX
    */ 
    uint8_t _txPin;

    /**
     * @fn void sendCmd(uint8_t cmd, uint16_t dat)
     * @brief message envoyé au module
    */ 
    void sendCmd(uint8_t cmd, uint16_t dat); 

  public : 
    /**
     * @fn SONMP3(uint8_t rx, uint8_t tx)
     * @brief Constructeur : on définit les pins ici
    */ 
    SONMP3(uint8_t rx, uint8_t tx);
    
    /**
     * @fn ~SONMP3()
     * @brief Destructeur
    */ 
    ~SONMP3();

    // Méthodes de base

     /**
     * @fn void initialiser()
     * @brief initialisation de l'actionneur MP3
    */ 
    void initialiser();

    /**
     * @fn void playSong(uint8_t file)
     * @brief joue l'audio file 
    */ 
    void playSong(uint8_t file);

    /**
     * @fn setVolume(uint8_t volume)
     * @brief règle le volume entre 0 et 30
    */    
    void setVolume(uint8_t volume);

    /**
     * @fn eteindre()
     * @brief coupe l'audio 
    */    
    void eteindre();

};
#endif