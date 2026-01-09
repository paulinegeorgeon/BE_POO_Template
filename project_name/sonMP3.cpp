/*********************************************************************
 * @file  MP3.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "sonMP3.h"


MP3::MP3(uint8_t rxPin, uint8_t txPin) : Actionneurs(rxPin)
{
  _rxPin = rxPin;
  _txPin = txPin;
  _mp3Serial = new SoftwareSerial(_rxPin, _txPin); 
}
  
MP3::~MP3()
{
  delete _mp3Serial;
}  

void MP3::initialiser(uint8_t defaultVolume)
{
  Serial.begin(9600); 

  _mp3Serial->begin(9600);


  _player.init(*_mp3Serial);


  setVolume(defaultVolume);
}


void MP3::playAudio(uint8_t folder, uint8_t index)
{
  _player.playSongSpecify(folder, index);
}

void MP3::stop()
{
  _player.stop();
}

void MP3::setVolume(uint8_t volume)
{
  if (volume > 30){
    volume = 30;
  }
  setVolume(volume);
  
}

