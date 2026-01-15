/*********************************************************************
 * @file  Ecran_LED.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier Ecran_LED hérite de Actionneurs
 *********************************************************************/

#include "Ecran_LED.h"

Ecran_LED::Ecran_LED():Actionneurs(0) //constructeur null
{
    ;
};

Ecran_LED::~Ecran_LED() //destructeur
{
    ;
}

void Ecran_LED::initialiser() {
    lcd.begin(16, 2); // Ecran 16 colonnes, 2 lignes [cite: 98]
    lcd.setRGB(255, 255, 255); // Blanc par défaut
    lcd.print("Nouvelle partie!");
}

void Ecran_LED::eteindre(){
    lcd.setRGB(0, 0, 0); // Blanc par défaut
}

void Ecran_LED::Afficher_message(String ligne1, String ligne2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(ligne1);
    if (ligne2 != "") {
        lcd.setCursor(0, 1);
        lcd.print(ligne2);
    }
}