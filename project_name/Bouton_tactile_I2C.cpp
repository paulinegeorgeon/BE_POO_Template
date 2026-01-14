/*********************************************************************
 * @file  Bouton_tactile_I2C.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe bouton tactile I2C qui hérite de capteurs
 *********************************************************************/

#include "Bouton_tactile_I2C.h"

i2ctouchsensor touchsensor;

Bouton_tactile_I2C::Bouton_tactile_I2C(){ ///constructeur
}; 


void Bouton_tactile_I2C::initialiser(){ //initialise tout l'I2C touch sensor 
  Wire.begin();
  touchsensor.initialize();   
};

/*
int Bouton_tactile_I2C::getValue (){
  touchsensor.readTouchInputs();
  touchsensor.getTouchState();
  if (touchsensor.touched & (1<<Num_Capteur)){
    return 1;
  }
  return 0 ; 
    //Wire.requestFrom(0x5A, (uint8_t)1); //l'I2C envoi un octet 
    //if (Wire.available()) { //vérifie si les données sont disponibles 
    //    uint8_t data = Wire.read(); //lit les données de l'I2C
    //   return (data & (1 << Num_Capteur)? 1 : 0); //retourne la valeur du num_capteur  
    //}
    //else return 0;
};*/

int Bouton_tactile_I2C::joueurAppuye() {

    touchsensor.readTouchInputs();
    touchsensor.getTouchState();

    for (int i = 0; i < 12; i++) {   //parcours les 5 capteurs pour savoir lequel est appuyé 

      if (touchsensor.touched & (1 << i)) {
        if (i<5){
          return i + 1;  // retourne le numéro du joueur qui touche le capteur 
        }
        else {
          return i-3; 
        }
      }
    }
    return -1;  // aucun joueur ne touche le capteur 
}

