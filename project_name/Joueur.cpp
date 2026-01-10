#include "Joueur.h"
#include <iostream> 
#include "string.h"
using namespace std;

Joueur::Joueur() {
  estmort = false;
  nbGorgees =7;
  Role="";
  estImmunise=false;
}

Joueur::~Joueur() {
  ;
}

void Joueur::setRole(String ro) {
  Role=ro; 
}

String Joueur::getRole(){
  return Role;
}

void Joueur::setNbGorgees(int Go){
  nbGorgees = Go;
}

int Joueur::getNbGorgees() {
  return nbGorgees;
}

void Joueur::setEstMort(bool EstMort) {
  estmort = EstMort;
}

bool Joueur::getEstMort() {
  return estmort;
}
void Joueur::setImmunise() {
  estImmunise = true;
}

bool Joueur::getImmunise(){
  return estImmunise;
}