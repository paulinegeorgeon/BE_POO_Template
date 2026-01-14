#include "Jour.h"


Jour::Jour(Jeu& j, Ecran_LED& e, SONMP3& s, Bouton_tactile_I2C& b) 
: jeuRef(j), ecranRef(e), sonRef(s), bouton(b)
{
}


void Jour::EstMort(){
    for (int i = 0; i < 6; i++) {
        Joueur* p = jeuRef.getJoueur(i);

        if (p != nullptr) {
            if (!p->getEstMort() && p->getNbGorgees() <= 0) {
                p->setEstMort(true);

                String ligne1 = "Joueur " + String(i + 1) ;
                String ligne2 = "est mort";
                ecranRef.Afficher_message(ligne1, ligne2);
            }
        }
    }
    
}

void Jour::RecapGorgees(){
    for (int i = 0; i < 6; i++) {
        Joueur* p = jeuRef.getJoueur(i);

        String ligne1 = "Joueur " + String(i + 1) ;
        String ligne2 = String(p->getNbGorgees()) + " gorgees";
        ecranRef.Afficher_message(ligne1, ligne2);
        delay(3000); // 3 secondes pour lire par joueur
    }
}

void Jour::QuiGagne(){
    int vivantsVillageois = 0;
    int vivantsGratteurs = 0;

    for (int i = 0; i < 6; i++) {
        Joueur* j = jeuRef.getJoueur(i);
        if (j != nullptr && !j->getEstMort()) {
            if (j->getRole() == "Gratteur de verre") {
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
        delay(10000);
        ecranRef.eteindre();
    }

    if (vivantsGratteurs >= vivantsVillageois) {
        String ligne1 = "Les Gratteurs" ;
        String ligne2 = "gagnent";
        delay(1000);
        ecranRef.Afficher_message(ligne1, ligne2);
        delay(10000);
        ecranRef.eteindre();
    }

}

void Jour::lancerLeJour() {
    ecranRef.Afficher_message("Le soleil", "se leve...");
    sonRef.playSong(1);
    delay(2000);


    ecranRef.Afficher_message("Recapitulatif", "des scores...");
    sonRef.playSong(2);
    RecapGorgees();
    delay(2000);

    EstMort();

    QuiGagne();

    //peut-être afficher qui est mort
    sonRef.playSong(3);
    ecranRef.Afficher_message("Vote du village", "Qui sauver ?"); 
    delay(10000);
    ecranRef.Afficher_message("Appuyez sur", "un joueur");
    delay(10000);
    sonRef.playSong(4);

    int elu = bouton.joueurAppuye();

    jeuRef.retirerGorgees(elu); 
    jeuRef.retirerGorgees(elu); 
    
    sonRef.playSong(5);
    ecranRef.Afficher_message("Le joueur " + String(elu), "perd 2 gorgees");
    delay(3000);

    sonRef.playSong(2);
    ecranRef.Afficher_message("Recapitulatif", "des scores...");
    delay(2000);

    RecapGorgees();
    EstMort();

    QuiGagne();

    //faire audio "retour à la nuit"
    ecranRef.Afficher_message("Fin du tour", "La nuit revient");
    delay(2000);

}