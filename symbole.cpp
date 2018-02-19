#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Symbole::setIdent(int ident)
{
   this->ident = ident;
}

void Entier::setVal(int val) {
    this->valeur = val;
}

int Entier::getVal() {
    return valeur;
}