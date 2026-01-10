/*********************************************************************
 * @file  sonMP3.h
 * @author Emma/Raksika/Pauline
 * @brief Fichier sonMP3 hérite de Actionneurs
 *********************************************************************/
 
#ifndef SONMP3_H
#define SONMP3_H


#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Actionneurs.h"
using namespace std;


/**
  * @class SONMP3
  * @brief Classe SONMP3
*/  

class SONMP3 : public Actionneurs
{
  protected : 

    SoftwareSerial* _serial;
    uint8_t _rxPin;
    uint8_t _txPin;
    void sendCmd(uint8_t cmd, uint16_t dat); 

  public : 
    // Constructeur : on définit les pins ici
    SONMP3(uint8_t rx, uint8_t tx);
    
    // Destructeur
    ~SONMP3();

    // Méthodes de base
    void initialiser();
    void playSong(uint8_t file);
    void setVolume(uint8_t volume);
    void eteindre();
};
#endif