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
#include "Jour.h"

Ecran_LED MonEcran;
Jeu NouveauJeu;
SONMP3 MonSon(14,12);
Bouton_tactile_I2C bouton;
Nuit MaNuit(NouveauJeu,MonEcran, MonSon, bouton);
Jour MonJour(NouveauJeu,MonEcran, MonSon, bouton);


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
  bouton.initialiser(); 
}


void Application::run(void)
{
  //MonSon.playSong(1);
  //MonEcran.Afficher_message("Tout le monde","dort sauf J1!");
  /*
  MonEcran.Afficher_message("Joueur ", String(bouton.joueurAppuye())); 
  delay(3000);   
  MonEcran.Afficher_message("Joueur ", String(bouton.joueurAppuye())); 
  delay(3000); */
  for (int i = 0; i < 6; i++) {
  MonEcran.Afficher_message("Joueur" + String(i + 1), NouveauJeu.getJoueur(i)->getRole());
  delay(1000);
  }
  MonJour.setPartieFinie(false);

  while (MonJour.getPartieFinie() == false) {
  MaNuit.lancerLaNuit();
  MonJour.lancerLeJour();
  }
}
