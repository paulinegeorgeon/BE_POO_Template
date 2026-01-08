
#include "Ecran_LED.h"
#include "Actionneurs.h"


void Ecran_LED::initialiser() {
    _lcd.begin(16, 2); // Ecran 16 colonnes, 2 lignes [cite: 98]
    _lcd.setRGB(255, 255, 255); // Blanc par défaut
    _lcd.print("Systeme Pret");
}

void Ecran_LED::eteindre() {
    _lcd.clear();
    _lcd.setRGB(0, 0, 0); // Noir
}

void MonEcran::afficherMessage(String ligne1, String ligne2) {
    _lcd.clear();
    _lcd.setCursor(0, 0);
    _lcd.print(ligne1);
    if (ligne2 != "") {
        _lcd.setCursor(0, 1);
        _lcd.print(ligne2);
    }
}