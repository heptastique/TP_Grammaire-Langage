#include "symbole.h"
#include <iostream>

Symbole::Symbole(int id)
{
	this->id = id;
}

Symbole::~Symbole()
{

}

Symbole::operator int() const
{
	return id;
}

void Symbole::affiche()
{
	cout << etiquettes[id];
}

void Entier::affiche()
{
	Symbole::affiche();
	cout << "(" << valeur << ")";
}

