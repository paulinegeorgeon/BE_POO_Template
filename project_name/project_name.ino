#include "Application.h"


Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();
  Ecran_LCD.initialiser();
  Ecran_LCD.afficherMessage("Coucou","Les loups se réveillent");

}
