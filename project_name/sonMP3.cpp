/*********************************************************************
 * @file  sonMP3.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier sonMP3 hérite de Actionneurs
 *********************************************************************/
 
#include "sonMP3.h"

SONMP3::SONMP3(uint8_t rx, uint8_t tx) : Actionneurs(rx){ //constructeur 
  _rxPin = rx;
  _txPin = tx;
  _serial = new SoftwareSerial(_rxPin, _txPin);
}

SONMP3::~SONMP3() {
  delete _serial;
}

void SONMP3::initialiser() {
  _serial->begin(9600); //Ouvre le canal de communication à une vitesse de 9600 bauds
  delay(500);
  sendCmd(0x09, 0x0002); // commande pour dire au module de lire les fichiers sur la carte SD
  delay(200);
}

void SONMP3::sendCmd(uint8_t cmd, uint16_t dat) { //cmd = commande, dat = paramètre
  uint8_t buf[8] = {0x7E, 0xFF, 0x06, cmd, 0x00, (uint8_t)(dat >> 8), (uint8_t)dat, 0xEF};
  for (uint8_t i = 0; i < 8; i++) {
    _serial->write(buf[i]);
  }
}

void SONMP3::playSong(uint8_t file) {
  sendCmd(0x12, file); //0x12 = MP3
}

void SONMP3::setVolume(uint8_t volume) {
  if (volume > 30) volume = 30;
  sendCmd(0x06, (uint16_t)volume); //0x6 commande de regler le volume
}

void SONMP3::eteindre() {
  sendCmd(0x16, 0x0000); //0x16 commande de stop
}
