/*********************************************************************
 * @file  Bouton_tactile.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe bouton tactile qui hérite de capteurs
 *********************************************************************/

#include <Arduino.h>
#include "Bouton_tactile.h"

using namespace std;

Bouton_tactile::Bouton_tactile(int p) : Capteurs(p){}; //constructeur avec le pin associé au bouton tactile 

int Bouton_tactile::getValue (){
  sensorValue = digitalRead(pin); 
  return sensorValue; 
};

void Bouton_tactile::initialiser(){
  pinMode(pin, INPUT); 
}
