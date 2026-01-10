#include "Nuit.h"

Nuit::Nuit(Jeu& j, Ecran_LED& e) 
: jeuRef(j), ecranRef(e)
{
}


int Nuit::selectionnerJoueur(){
  return 1;
}

// --- LES TOURS SPÉCIFIQUES ---

void Nuit::tourBarman() {
    ecranRef.Afficher_message("Le Barman", "se reveille");
    delay(2000);

    // rajout fonction MP3
    ecranRef.Afficher_message("Barman", "Qui faire boire?");

    int cible = selectionnerJoueur(); 
    
    jeuRef.ajouterGorgees(cible);
    
    ecranRef.Afficher_message("C'est fait !", "");
    delay(1000);
}

void Nuit::tourGratteur() {
    ecranRef.Afficher_message("Le Gratteur", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Gratteur", "Qui soulager?");
            
      if (cntGratteurs ==2) {
    int cible = selectionnerJoueur();
    int cible2 = selectionnerJoueur();
    jeuRef.retirerGorgees(cible);
    jeuRef.retirerGorgees(cible2);
      } else {
        int cible = selectionnerJoueur();
        jeuRef.retirerGorgees(cible);
      }
     
    delay(1000);
}

void Nuit::tourCDV() {
    ecranRef.Afficher_message("La Capote", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Capote :", "Qui proteger ?");
    
    int cible = selectionnerJoueur(); 
    
    jeuRef.immuniserJoueur(cible);
    
    ecranRef.Afficher_message("Joueur " + String(cible + 1), "est protege !");
    delay(2000);
    
    ecranRef.Afficher_message("La Capote", "se rendort");
    delay(1000);
}

void Nuit::tourMaladroit() {
    ecranRef.Afficher_message("Le Maladroit", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Maladroit :", "Qui renverser ?");
    
    int cible = selectionnerJoueur();
    

    jeuRef.retirerGorgees(cible);
    
    ecranRef.Afficher_message("Oups ! Verre", "renverse...");
    delay(2000);
    
    ecranRef.Afficher_message("Le Maladroit", "se rendort");
    delay(1000);
}

void Nuit::tourEthylotest() {
    ecranRef.Afficher_message("L'Ethylotest", "se reveille");
    delay(2000);
    
    ecranRef.Afficher_message("Ethylotest :", "Qui tester ?");
    
    int cible = selectionnerJoueur();
    
    Joueur* pJoueur = jeuRef.getJoueur(cible);
    int nbGorgees = pJoueur->getNbGorgees();
    
    ecranRef.Afficher_message("Resultat :", String(nbGorgees) + " gorgees");
    
    delay(4000);
    
    ecranRef.Afficher_message("Analyse", "terminee");
    delay(1000);
    
    ecranRef.Afficher_message("L'Ethylotest", "se rendort");
    delay(1000);
}


// --- LE CHEF D'ORCHESTRE ---

void Nuit::lancerLaNuit() {
    // 0. Reset des stats temporaires a faire 
    //jeuRef.resetTour();
    ecranRef.Afficher_message("La Nuit", "Tombe...");
    delay(2000);

    // 1. Scénario
    tourBarman();
    tourCDV();
    tourGratteur();
    tourEthylotest(); 
    tourMaladroit();

    // Fin
    ecranRef.Afficher_message("Le Village", "Se reveille !");
    delay(2000);
}