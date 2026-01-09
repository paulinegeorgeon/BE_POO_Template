/*********************************************************************
 * @file  MP3.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "sonMP3.h"


MP3::MP3(uint8_t rxPin, uint8_t txPin)
{
  _rxPin = rxPin;
  _txPin = txPin;
  _mp3Serial = new SoftwareSerial(_rxPin, _txPin); 
}
  
MP3::~MP3()
{
  delete _mp3Serial;
}  

void MP3::init(uint8_t defaultVolume)
{
  mp3Serial->begin(9600);
    
  // On doit lier la bibliothèque à notre instance de SoftwareSerial
  // Note : La bibliothèque Seeed utilise souvent une liaison interne, 
  // on initialise ici le support de stockage.
  delay(500); // Temps de réveil du module
  SelectPlayerDevice(0x02); // 0x02 sélectionne la carte SD
  setVolume(defaultVolume);
}


void MP3::playAudio(uint8_t folder, uint8_t index)
{
  SpecifyMusicPlay(folder, index);
}

void MP3::stop()
{
  StopPlay();
}

void MP3::setVolume(uint8_t volume)
{
  // Le module accepte des valeurs de 0x00 à 0x1E (0 à 30)
  if (volume > 30) volume = 30;
  SetVolume(volume);
}

void MP3::next()
{
  PlayNext();
}

void MP3::previous()
{
  PlayPrevious();
}