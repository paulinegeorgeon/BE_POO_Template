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

  //----DISTRIBUTION DES ROLES----
  for (int i = 0; i < 6; i++) {
      MonEcran.Afficher_message("Joueur " + String(i + 1), "Appuie pr voir");

      // On attend qu'il appuie sur un bouton
      int interaction = -1; 
      while (interaction == -1){
        interaction = bouton.joueurAppuye(); 
        delay(50); 
      }
      delay(500);

      String role = NouveauJeu.getJoueur(i)->getRole();
      MonEcran.Afficher_message("Tu es :", role);
      delay(2000); 

      MonEcran.Afficher_message(role, "OK ? (Appuie)");
      
      interaction = -1;
      while (interaction == -1){
        interaction = bouton.joueurAppuye();
        delay(50);
      }
      delay(500);

      MonEcran.Afficher_message("passe au", "joueur suivant");
      delay(2000);
  }

  //LANCEMENT DU JEU  
  
  MonJour.setPartieFinie(false);

  while (MonJour.getPartieFinie() == false) {
  MaNuit.lancerLaNuit();

  MonJour.lancerLeJour();
  }

}
