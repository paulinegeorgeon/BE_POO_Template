/*********************************************************************
 * @file  Nuit.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Fichier classe Nuit qui prévoit le déroulement d'une nuit de jeu
 *********************************************************************/

#include "Nuit.h"

Nuit::Nuit(Jeu& j, Ecran_LED& e, SONMP3& s, Bouton_tactile_I2C& b) //constructeur 
: jeuRef(j), ecranRef(e), sonRef(s), bouton(b)
{
}

void Nuit::initNuit(){
  for (int i=0; i<6; i++){
    jeuRef.immuniserJoueur(i,false); 
  }
}

// Fonctions des différents tours au cours de la nuit 

// TOUR DU BARMAN
void Nuit::tourBarman() {
  sonRef.playSong(6);
  ecranRef.Afficher_message("Le Barman", "se reveille");
  delay(2000);
  ecranRef.Afficher_message("Barman", "Qui faire boire?");
  delay(1000); 

  //attente que le barman appuie sur un bouton
  int cible = -1; 
  while (cible==-1){
    cible = bouton.joueurAppuye(); 
    delay(50); 
  }

  jeuRef.ajouterGorgees(cible-1);
  delay(2000);
  ecranRef.Afficher_message("C'est fait !", "");
  delay(2000);
  sonRef.playSong(7);
  delay(5000);
}

//TOUR DU GRATTEUR
void Nuit::tourGratteur() {
  sonRef.playSong(8);
  ecranRef.Afficher_message("Le Gratteur", "se reveille");
  delay(2000);
  ecranRef.Afficher_message("Gratteur(s)", "Qui soulager?");  

  //attente que le gratteur appuie sur un bouton
  int cible = -1; 
  while (cible==-1){
    cible = bouton.joueurAppuye(); 
    delay(50); 
  }

  jeuRef.retirerGorgees(cible-1);
  jeuRef.retirerGorgees(cible-1);
  delay(2000);
  ecranRef.Afficher_message("C'est fait !", "");
  delay(3000);
  sonRef.playSong(9);
  delay(5000);
}

//TOUR DU PROTEGE VERRRE
void Nuit::tourProtege() {
  sonRef.playSong(10);
  ecranRef.Afficher_message("Le Protecteur", "se reveille");
  delay(2000);
  ecranRef.Afficher_message("Protecteur :", "Qui proteger ?");
  
  //attente que la capote appuie sur un bouton
  int cible = -1; 
  while (cible==-1){
    cible = bouton.joueurAppuye(); 
    delay(50); 
  }

  jeuRef.immuniserJoueur(cible-1, true);
  
  delay(2000);
  ecranRef.Afficher_message("Joueur " + String(cible), "est protege !");
  delay(2000);
  
  ecranRef.Afficher_message("Le Protecteur", "se rendort");
  delay(1000);
  sonRef.playSong(11);
  delay(5000);
}

//TOUR DU MALADROIT
void Nuit::tourMaladroit() {
  sonRef.playSong(12);
  ecranRef.Afficher_message("Le Maladroit", "se reveille");
  delay(2000);
  ecranRef.Afficher_message("Maladroit :", "Qui renverser ?");
  
  //attente que le maladroit appuie sur un bouton
  int cible = -1; 
  while (cible==-1){
    cible = bouton.joueurAppuye(); 
    delay(50); 
  }

  jeuRef.retirerGorgees(cible-1);

  delay(2000);    
  ecranRef.Afficher_message("Oups ! Verre", "renverse...");
  delay(2000);
  
  ecranRef.Afficher_message("Le Maladroit", "se rendort");
  delay(2000);
  sonRef.playSong(13);
  delay(5000);
}

//TOUR ETHYLOTEST
void Nuit::tourEthylotest() {
  sonRef.playSong(14);
  ecranRef.Afficher_message("L'Ethylotest", "se reveille");
  delay(2000);
  ecranRef.Afficher_message("Ethylotest :", "Qui tester ?");
  
  //attente que le maladroit appuie sur un bouton
  int cible = -1; 
  while (cible==-1){
    cible = bouton.joueurAppuye(); 
    delay(50); 
  }
  
  Joueur* pJoueur = jeuRef.getJoueur(cible-1);
  int nbGorgees = pJoueur->getNbGorgees();
  
  ecranRef.Afficher_message("Resultat :", String(nbGorgees) + " gorgees");
  delay(3000);
  
  ecranRef.Afficher_message("Analyse", "terminee");
  delay(1000);
  
  ecranRef.Afficher_message("L'Ethylotest", "se rendort");
  delay(1000);
  sonRef.playSong(15);
  delay(5000);
}



//NUIT ENTIERE
void Nuit::lancerLaNuit() {

    // Initialisaiton de la nuit
    initNuit(); 
    ecranRef.Afficher_message("La Nuit", "Tombe...");
    //sonRef.playSong(16);
    delay(2000);

    // Déroulement de la nuit
    tourBarman();
    delay(2000);
    tourProtege();
    delay(2000);
    tourGratteur();
    delay(2000);
    tourEthylotest(); 
    delay(2000);
    tourMaladroit();
    delay(2000);

    // Fin de la nuit
    ecranRef.Afficher_message("Le Village", "Se reveille !");
    delay(2000);
}