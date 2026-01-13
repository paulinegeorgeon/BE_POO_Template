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

// Fonctions des différents tours au cours de la nuit 

// TOUR DU BARMAN
void Nuit::tourBarman() {
    ecranRef.Afficher_message("Le Barman", "se reveille");
    delay(2000);

    // rajout fonction MP3
    ecranRef.Afficher_message("Barman", "Qui faire boire?");
    delay(1000); 
    int cible = bouton.joueurAppuye(); //mettre un décompte à l'écran 
    jeuRef.ajouterGorgees(cible);
    ecranRef.Afficher_message("C'est fait !", "");
    delay(1000);
}

//TOUR DU GRATTEUR
void Nuit::tourGratteur() {
    ecranRef.Afficher_message("Le Gratteur", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Gratteur", "Qui soulager?");
            
      if (cntGratteurs ==2) {
    int cible = bouton.joueurAppuye();
    int cible2 = bouton.joueurAppuye();
    jeuRef.retirerGorgees(cible);
    jeuRef.retirerGorgees(cible2);
      } else {
        int cible = bouton.joueurAppuye();
        jeuRef.retirerGorgees(cible);
      }

    delay(1000);
}

//TOUR DE LA CAPOTE DE VERRE
void Nuit::tourCDV() {
    ecranRef.Afficher_message("La Capote", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Capote :", "Qui proteger ?");
    
    int cible = bouton.joueurAppuye(); 
    
    jeuRef.immuniserJoueur(cible);
    
    ecranRef.Afficher_message("Joueur " + String(cible + 1), "est protege !");
    delay(2000);
    
    ecranRef.Afficher_message("La Capote", "se rendort");
    delay(1000);
}

//TOUR DU MALADROIT
void Nuit::tourMaladroit() {
    ecranRef.Afficher_message("Le Maladroit", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Maladroit :", "Qui renverser ?");
    
    int cible = bouton.joueurAppuye();
    

    jeuRef.retirerGorgees(cible);
    
    ecranRef.Afficher_message("Oups ! Verre", "renverse...");
    delay(2000);
    
    ecranRef.Afficher_message("Le Maladroit", "se rendort");
    delay(1000);
}

//TOUR ETHYLOTEST
void Nuit::tourEthylotest() {
    ecranRef.Afficher_message("L'Ethylotest", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Ethylotest :", "Qui tester ?");
    
    int cible = bouton.joueurAppuye();
    
    Joueur* pJoueur = jeuRef.getJoueur(cible);
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

    // 0. Reset des stats temporaires a faire 
    //jeuRef.resetTour();
    ecranRef.Afficher_message("La Nuit", "Tombe...");
    sonRef.playSong(1);
    delay(2000);

    // 1. Scénario
    tourBarman();
    delay(2000);
    tourCDV();
    delay(2000);
    tourGratteur();
    delay(2000);
    tourEthylotest(); 
    delay(2000);
    tourMaladroit();
    delay(2000);
    // Fin
    ecranRef.Afficher_message("Le Village", "Se reveille !");
    delay(2000);
}