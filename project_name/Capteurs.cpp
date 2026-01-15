/*********************************************************************
 * @file  Capteurs.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe capteur qui hérite de périphériques
 *********************************************************************/

#include "Capteurs.h"

Capteurs::Capteurs(int p) : Peripheriques(p){}; //constructeur avec le pin associé au périph

Capteurs::Capteurs() : Peripheriques(){}; //constructeur avec le pin associé au périph

Capteurs::~Capteurs(){}; //destructeur