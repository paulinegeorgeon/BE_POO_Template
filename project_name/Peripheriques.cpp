/*********************************************************************
 * @file  Peripheriques.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier header pour tous les périphs
 *********************************************************************/

#include "Peripheriques.h"

using namespace std;

Peripheriques::Peripheriques(){  //Constructeur nul
}; 


Peripheriques::Peripheriques(int p){  //Constructeur avec le în associé au periph 
      pin = p; 
}; 

Peripheriques::~Peripheriques(){}; //destructeur