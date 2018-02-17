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

void Symbole::print()
{
	cout << etiquettes[id];
}

void Symbole::setId(int id)
{
	this->id = id;
}

void Entier::print()
{
	Symbole::print();
	cout << "(" << valeur << ")";
}

int Entier::getValeur()
{
	return this->valeur;
}

void Entier::setValeur(int valeur)
{
	this->valeur = valeur;
}
