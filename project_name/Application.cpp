/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Ecran_LED.h"
#include "Bouton_tactile.h"
#include "Jeu.h"
#include "sonMP3.h"
#include "Nuit.h"

Ecran_LED MonEcran;

Bouton_tactile MyBouton(13);

Jeu NouveauJeu;
SONMP3 MonSon(14,12);
Nuit MaNuit(NouveauJeu,MonEcran);

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
  NouveauJeu.RepartitionRoles();
  MonSon.initialiser();
  MonSon.setVolume(20);
}


void Application::run(void)
{
  MonSon.playSong(1);
  MonEcran.Afficher_message("Tout le monde","dort sauf J1!");
  delay(10000); 
  MonEcran.Afficher_message("Bouton appuyé? ", String(MyBouton.getValue())); 
  delay(1000);   
  for (int i = 0; i < 6; i++) {
  MonEcran.Afficher_message("Joueur" + String(i + 1), NouveauJeu.getJoueur(i)->getRole());
  delay(10000);
  MaNuit.lancerLaNuit();

    }
}
