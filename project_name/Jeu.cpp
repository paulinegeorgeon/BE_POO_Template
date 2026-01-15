/*********************************************************************
 * @file  Jeu.h
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Classe de descrpition des règles du jeu 
 *********************************************************************/

#include "Jeu.h"

Jeu::Jeu() {
  ;
}

Jeu::~Jeu() {
  ;
}

void Jeu::RepartitionRoles() {

    // on mélange le tableau rolesDisponibles
    // mélange simple : on échange deux cases au hasard plusieurs fois
    for (int i = 0; i < 6; i++) {
        int r = random(6); // un nombre entre 0 et 5
        
        // Echange (swap)
        String temp = rolesDisponibles[i];
        rolesDisponibles[i] = rolesDisponibles[r];
        rolesDisponibles[r] = temp;
      }

    //distribution des rôles 
    for (int i = 0; i < 6; i++) {
          listeJoueurs[i].setRole(rolesDisponibles[i]);
          
          listeJoueurs[i].setNbGorgees(7); // Initialisation des gorgées à 7
          listeJoueurs[i].setEstMort(false); // Initialisation joueur vivant
          listeJoueurs[i].setImmunise(false); //initialisation de l'immunité des joueurs
          
          Serial.print("Joueur "); //affichage des rôles
          Serial.print(i);
          Serial.print(" est : ");
          Serial.println(listeJoueurs[i].getRole());
      }
}

Joueur* Jeu::getJoueur(int index) {
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

void Jeu::immuniserJoueur(int index, bool EstImm) {
  listeJoueurs[index].setImmunise(EstImm);
}
 
