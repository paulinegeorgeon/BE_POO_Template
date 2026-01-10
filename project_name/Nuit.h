#ifndef NUIT_H
#define NUIT_H

#include <Arduino.h>
#include "Jeu.h"
#include "Ecran_LED.h"
#include "Actionneurs.h" 

class Nuit {
  private:

    Jeu& jeuRef;
    Ecran_LED& ecranRef;
    Actionneurs& actionneursRef;
    int cntGratteurs;

    /**
     * @brief Fonction interne pour gérer l'interface de choix avec les boutons
     * @return L'index du joueur choisi (0-5)
     */
    int selectionnerJoueur();

    // Sous-fonctions pour chaque rôle (pour ne pas avoir un code géant)
    void tourBarman();
    void tourGratteur();
    void tourEthylotest();
    void tourMaladroit();
    void tourCDV();

  public:
    // Constructeur qui prend les objets existants
    Nuit(Jeu& jeu, Ecran_LED& ecran, Actionneurs& actionneurs);

    // La fonction principale qui lance toute la séquence
    void lancerLaNuit();
};

#endif