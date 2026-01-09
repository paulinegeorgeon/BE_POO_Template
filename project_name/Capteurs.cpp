/*********************************************************************
 * @file  Capteurs.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe capteur qui hérite de périphériques
 *********************************************************************/

#include <iostream> 
#include "string.h"
#include "math.h"
#include "Capteurs.h"
#include "Peripheriques.h"

using namespace std;

Capteurs::Capteurs(int p) : Peripheriques(p){}; //constructeur avec le pin associé au périph