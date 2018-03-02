#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

int Symbole::eval()
{
	return 0;
}

int Symbole::getIdent()
{
	return this->ident;
}
     
void Symbole::setIdent(int ident)
{
	this->ident = ident;
}

void Entier::Affiche()
{
   cout<<valeur;
}

