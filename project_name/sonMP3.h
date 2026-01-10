#ifndef MP3_H
#define MP3_H

#include "Actionneurs.h"
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h> //plus simple apparemment ??

class MP3 : public Actionneurs{
  private:
    SoftwareSerial* _mp3Serial;
    DFRobotDFPlayerMini _player; 

  public:
    //constructeur 
    MP3(uint8_t rxPin, uint8_t txPin) : Actionneurs(rxPin){
        _mp3Serial = new SoftwareSerial(rxPin, txPin);
    }

    //plus de virtual 
    void initialiser() {
        _mp3Serial->begin(9600);
        if (!_player.begin(*_mp3Serial)) {
            Serial.println("Erreur de communication avec le module MP3");
        }
        _player.volume(20); 
    }

    void playAudio(uint8_t folder, uint8_t index) {
        _player.playFolder(folder, index);
    }

    void eteindre() {
      _player.stop();
    }  
};

#endif