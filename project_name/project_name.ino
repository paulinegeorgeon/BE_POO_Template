#include "Application.h"
#include "Ecran_LED.h"

Application myApplication;

Ecran_LED MonEcran;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init(); 
  MonEcran.initialiser();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();
 MonEcran.Afficher_message("Coucou","Les loups se réveillent");

}
