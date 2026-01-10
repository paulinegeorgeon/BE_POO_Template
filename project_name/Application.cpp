/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Ecran_LED.h"
#include "Bouton_tactile_I2C.h"
#include "Jeu.h"
#include "sonMP3.h"
#include "Nuit.h"

Ecran_LED MonEcran;
Jeu NouveauJeu;
SONMP3 MonSon(14,12);
Nuit MaNuit(NouveauJeu,MonEcran);
Bouton_tactile_I2C joueur1(0);
Bouton_tactile_I2C joueur2(1);  

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
  NouveauJeu.RepartitionRoles();
  MonSon.initialiser();
  MonSon.setVolume(20);
  joueur1.initialiser(); 
}


void Application::run(void)
{
  //MonSon.playSong(1);
  //MonEcran.Afficher_message("Tout le monde","dort sauf J1!");
  //delay(10000); 
  MonEcran.Afficher_message("Bouton appuyé? ", String(joueur1.getValue())); 
  delay(3000);   
  MonEcran.Afficher_message("Bouton  ", String(joueur2.getValue())); 
  delay(3000); 
  //for (int i = 0; i < 6; i++) {
  //MonEcran.Afficher_message("Joueur" + String(i + 1), NouveauJeu.getJoueur(i)->getRole());
  //delay(10000);
  //MaNuit.lancerLaNuit();

   // }
}
