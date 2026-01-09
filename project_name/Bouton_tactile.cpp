/*********************************************************************
 * @file  Bouton_tactile.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe bouton tactile qui hérite de capteurs
 *********************************************************************/

#include <iostream> 
#include <Arduino.h>
#include "string.h"
#include "math.h"
#include "Bouton_tactile.h"
#include "Capteurs.h"
#include "Peripheriques.h"

using namespace std;

Bouton_tactile::Bouton_tactile(int p) : Capteurs(p){}; //constructeur avec le pin associé au bouton tactile 

int Bouton_tactile::getValue (){
  sensorValue = digitalRead(pin); 
  return sensorValue; 
};

void Bouton_tactile::initialiser(){
  pinMode(pin, INPUT); 
}
