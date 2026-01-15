/*********************************************************************
 * @file  Joueur.cpp
 * @author CALVO - YOGALINGAM - GEORGEON
 * @brief Classe d'un joueur 
 *********************************************************************/

#include "Joueur.h"

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
void Joueur::setImmunise(bool EstImm) {
  estImmunise = EstImm;
}

bool Joueur::getImmunise(){
  return estImmunise;
}