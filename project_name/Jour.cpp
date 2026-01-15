#include "Jour.h"


Jour::Jour(Jeu& j, Ecran_LED& e, SONMP3& s, Bouton_tactile_I2C& b) 
: jeuRef(j), ecranRef(e), sonRef(s), bouton(b)
{  
}

Jour::~Jour() {

};

bool Jour::getPartieFinie() {
    return PartieFinie;
}

void Jour::setPartieFinie(bool Resu){
    PartieFinie = Resu;
}


void Jour::EstMort(){
    for (int i = 0; i < 6; i++) {
        Joueur* p = jeuRef.getJoueur(i);

        if (p != nullptr) {
            if (!p->getEstMort() && p->getNbGorgees() <= 0) 
            {
                p->setEstMort(true);

                String ligne1 = "Joueur " + String(i + 1) ;
                String ligne2 = "est mort";
                ecranRef.Afficher_message(ligne1, ligne2);
                delay(3000);
            }
        }
    }
}

void Jour::RecapGorgees(){
    for (int i = 0; i < 6; i++) {
        Joueur* p = jeuRef.getJoueur(i);

        String ligne1 = "Joueur " + String(i+1) ;
        String ligne2 = String(p->getNbGorgees()) + " gorgees";

        if (p->getEstMort()) {
                ligne2 = "MORT";
        }

        ecranRef.Afficher_message(ligne1, ligne2);
        delay(3000); // 3 secondes pour lire par joueur
    }
}

int Jour::QuiGagne(){
    int vivantsVillageois = 0;
    int vivantsGratteurs = 0;

    for (int i = 0; i < 6; i++) {
        Joueur* j = jeuRef.getJoueur(i);
        if (j != nullptr && !j->getEstMort()) {
            if (j->getRole() == "Gratteur Verre") {
                vivantsGratteurs++;
            } else {
                vivantsVillageois++;
            }
        }
    }

    if (vivantsGratteurs == 0) {
        String ligne1 = "Les Villageois" ;
        String ligne2 = "gagnent";
        delay(1000);
        ecranRef.Afficher_message(ligne1, ligne2);


        delay(1000);
        ecranRef.eteindre();
        PartieFinie = true;
        return 1; // Code pour victoire villageois
    }

    if (vivantsGratteurs >= vivantsVillageois) {
        String ligne1 = "Les Gratteurs" ;
        String ligne2 = "gagnent";
        delay(1000);
        ecranRef.Afficher_message(ligne1, ligne2);


        delay(1000);
        ecranRef.eteindre();
        PartieFinie = true;
        return 2; // Code pour victoire gratteurs
    }
    else {
        return 0;
    }
}

void Jour::lancerLeJour() {
    sonRef.playSong(1);
    ecranRef.Afficher_message("Le soleil", "se leve...");
    delay(7000);


    ecranRef.Afficher_message("Recapitulatif", "des scores...");
    sonRef.playSong(2);
    RecapGorgees();
    delay(5000);

    EstMort();

    QuiGagne();

//VOTE DU VILLAGE
    sonRef.playSong(3);
    ecranRef.Afficher_message("Vote du village", "Qui sauver ?"); 
    delay(1000);
    ecranRef.Afficher_message("Appuyez sur", "un joueur");
    delay(3000);
    sonRef.playSong(4);
    delay(5000);

    int elu = -1; 
    while (elu==-1){
      elu = bouton.joueurAppuye(); 
      delay(50); 
    }


//RETIRER GORGEES APRES LE VOTE
    jeuRef.retirerGorgees(elu-1); 
    jeuRef.retirerGorgees(elu-1); 
    

    sonRef.playSong(5);
    ecranRef.Afficher_message("Le joueur " + String(elu), "perd 2 gorgees");
    delay(5000);

    sonRef.playSong(2);
    ecranRef.Afficher_message("Recapitulatif", "des scores...");
    delay(5000);
    RecapGorgees();
    EstMort();
    QuiGagne();


    //faire audio "retour à la nuit"
    ecranRef.Afficher_message("Fin du jour", " ");
    delay(2000);

}