#include "Jeu.h"

Jeu::Jeu() {
  ;
}

Jeu::~Jeu() {
  ;
}

void Jeu::RepartitionRoles() {
    // 1. D'abord, on mélange le tableau rolesDisponibles
    // Algorithme de mélange simple : on échange deux cases au hasard plusieurs fois
    
    for (int i = 0; i < 6; i++) {
        int r = random(6); // un nombre entre 0 et 5
        
        // Echange (swap)
        String temp = rolesDisponibles[i];
        rolesDisponibles[i] = rolesDisponibles[r];
        rolesDisponibles[r] = temp;
      }
    for (int i = 0; i < 6; i++) {
          // On prend le rôle i et on le donne au joueur i
          listeJoueurs[i].setRole(rolesDisponibles[i]);
          
          // On initialise aussi leurs gorgées à 7 par sécurité
          listeJoueurs[i].setNbGorgees(7);
          listeJoueurs[i].setEstMort(false);
          
          // Debug pour vérifier dans la console
          Serial.print("Joueur ");
          Serial.print(i);
          Serial.print(" est : ");
          Serial.println(listeJoueurs[i].getRole());
      }
}

Joueur* Jeu::getJoueur(int index) {
    // Sécurité : on vérifie que l'index est bien entre 0 et 5
    if (index >= 0 && index < 6) {
        return &listeJoueurs[index]; // On retourne l'adresse du joueur dans le tableau
    } else {
        return nullptr; // Retourne rien si l'index est invalide
    }
}

void Jeu::ajouterGorgees(int indexcible){
    listeJoueurs[indexcible].setNbGorgees(listeJoueurs[indexcible].getNbGorgees()+1);
}

void Jeu::retirerGorgees(int indexcible){
    if (!(listeJoueurs[indexcible].getImmunise())){
    listeJoueurs[indexcible].setNbGorgees(listeJoueurs[indexcible].getNbGorgees()-1);
    }
}

void Jeu::immuniserJoueur(int index) {
    
  listeJoueurs[index].setImmunise();
}
 
