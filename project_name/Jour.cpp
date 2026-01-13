#include "Jour.h"


Jour::Jour(Jeu& j, Ecran_LED& e, sonMP3& s) 
: jeuRef(j), ecranRef(e), sonRef(s)
{
}

void Jour::lancerLeJour() {
    ecranRef.afficherMessage("Le soleil", "se leve...");
    sonRef.playSong(1);
    delay(2000);
    ecranRef.setRGB(255, 255, 0);

    ecranRef.afficherMessage("Recapitulatif", "des scores...");
    sonRef.playSong(2);
    ecranRef.setRGB(255, 255, 255); 
    delay(2000);

    for (int i = 0; i < 6; i++) {
        Joueur* p = jeuRef.getJoueur(i);

        String ligne1 = "Joueur " + String(i + 1) + ;
        String ligne2 = String(p->getNbGorgees()) + " gorgees";
        ecranRef.afficherMessage(ligne1, ligne2);
        delay(3000); // 3 secondes pour lire par joueur
    }
     

    //peut-être afficher qui est mort
    sonRef.playSong(3);
    ecranRef.afficherMessage("Vote du village", "Qui sauver ?"); 
    delay(10000);
    ecranRef.afficherMessage("Appuyez sur", "un joueur");
    delay(10000);
    sonRef.playSong(4);

    int elu = selectionnerJoueur();

    jeuRef.retirerGorgees(elu); 
    jeuRef.retirerGorgees(elu); 
    
    sonRef.playSong(5);
    ecranRef.afficherMessage("Le joueur " + String(elu), "perd 2 gorgees");
    delay(3000);

    sonRef.playSong(2);
    ecranRef.afficherMessage("Recapitulatif", "des scores...");
    ecranRef.setRGB(255, 255, 255); 
    delay(2000);

    for (int i = 0; i < 6; i++) {
        Joueur* p = jeuRef.getJoueur(i);

        String ligne1 = "Joueur " + String(i) + ;
        String ligne2 = String(p->getNbGorgees()) + " gorgees";
        ecranRef.afficherMessage(ligne1, ligne2);
        delay(3000); // 3 secondes pour lire par joueur
    }

    //faire audio "retour à la nuit"
    ecranRef.afficherMessage("Fin du tour", "La nuit revient");
    delay(2000);
    ecranRef.setRGB(0, 0, 50); // Ecran bleu nuit un peu sombre
}