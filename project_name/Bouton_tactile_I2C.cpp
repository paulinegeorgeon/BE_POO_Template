/*********************************************************************
 * @file  Bouton_tactile_I2C.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe bouton tactile I2C qui hérite de capteurs
 *********************************************************************/

#include <Arduino.h>
#include "Bouton_tactile_I2C.h"

using namespace std;

Bouton_tactile_I2C::Bouton_tactile_I2C(uint8_t num_bouton){ //constructeur avec numéro du bouton tactile 
  Num_Capteur = num_bouton; 
}; 

int Bouton_tactile_I2C::getValue (){
    Wire.requestFrom(0x5A, (uint8_t)1); //l'I2C envoi un octet 
    if (Wire.available()) { //vérifie si les données sont disponibles 
        uint8_t data = Wire.read(); //lit les données de l'I2C
        return (data & (1 << Num_Capteur)); //retourne la valeur du num_capteur  
    }
    else return 0;
};


void Bouton_tactile_I2C::initialiser(){ //initialise tout l'I2C touch sensor 
  Wire.begin();
};