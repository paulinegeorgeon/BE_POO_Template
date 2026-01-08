#include "Actionneurs.h"


   Actionneurs::Actionneurs(int p) {p=pin};

   virtual void Actionneurs::initialiser() =0;

   virtual void Actionneurs::eteindre()=0;

}