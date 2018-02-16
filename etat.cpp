# include <iostream>

# include "etat.h"

Etat::Etat(string name)
{
	this->name = name;
}

Etat::~Etat()
{

}

void Etat::print() const
{
	cout << name;
}

// Transition
	// Symbole lu
bool Etat::transition (Automate & automage, Symbole * symbole)
{

}
