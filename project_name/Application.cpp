/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Ecran_LED.h"
#include "Bouton_tactile.h"

Ecran_LED MonEcran;

Bouton_tactile MyBouton(13);

Application::Application()
{
  // Code
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  MonEcran.initialiser();
  MyBouton.initialiser(); 
}


void Application::run(void)
{
  MonEcran.Afficher_message("Coucou","Les loups se réveillent");
  delay(1000); 
  MonEcran.Afficher_message("Bouton appuyé? ", String(MyBouton.getValue())); 
  delay(1000);
}
