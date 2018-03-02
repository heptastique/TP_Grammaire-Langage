#include "etat.h"

Etat::Etat(string name)
{
	this->name = name;
}

int Etat::transition(Automate & automate, Symbole * s)
{
	return 0;
}

Etat::~Etat() {}
