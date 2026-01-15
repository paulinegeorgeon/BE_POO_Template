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
  delay(3000);
}

//TOUR DU GRATTEUR
void Nuit::tourGratteur() {
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
}

//TOUR DU PROTEGE VERRRE
void Nuit::tourProtege() {
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
  delay(3000);
}

//TOUR DU MALADROIT
void Nuit::tourMaladroit() {
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
  delay(3000);
}

//TOUR ETHYLOTEST
void Nuit::tourEthylotest() {
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
  delay(4000);
  
  ecranRef.Afficher_message("Analyse", "terminee");
  delay(1000);
  
  ecranRef.Afficher_message("L'Ethylotest", "se rendort");
  delay(1000);
}



//NUIT ENTIERE
void Nuit::lancerLaNuit() {

    // Initialisaiton de la nuit
    initNuit(); 
    ecranRef.Afficher_message("La Nuit", "Tombe...");
    sonRef.playSong(1);
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