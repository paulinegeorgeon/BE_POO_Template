
#include "Ecran_LED.h"
#include "Actionneurs.h"

Ecran_LED::Ecran_LED():Actionneurs(0) 
{
    ;
};

Ecran_LED::~Ecran_LED()
{
    ;
}

void Ecran_LED::initialiser() {
    lcd.begin(16, 2); // Ecran 16 colonnes, 2 lignes [cite: 98]
    lcd.setRGB(255, 255, 255); // Blanc par défaut
    lcd.print("Systeme Pret");
}

void Ecran_LED::eteindre() {
    lcd.clear();
    lcd.setRGB(0, 0, 0); // Noir
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