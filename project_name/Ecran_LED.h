#include <iostream> 
#include "string.h"
#include "math.h"
#include <rgb_lcd.h>
#include "Actionneurs.h"

using namespace std;

class Ecran_LED : public Actionneurs{
  protected : 
    rgb_lcd lcd;
  public : 
    Ecran_LED() : Actionneurs(0);

    void initialiser() {}; // initialiser a 0
    void Afficher_message() {}; 
    void changer_couleur(){};
}