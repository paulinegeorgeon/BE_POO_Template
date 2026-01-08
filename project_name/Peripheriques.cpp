/*********************************************************************
 * @file  Peripheriques.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier header pour tous les périphs
 *********************************************************************/
 
#include <iostream> 
#include "string.h"
#include "math.h"
#include "Peripheriques.h"

using namespace std;

Peripheriques::Peripheriques(int p){  //Constructeur 
      pin = p; 
}; 

Peripheriques::~Peripheriques(){}; //destructeur