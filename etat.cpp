//
// Created by Vincent on 13/02/2018.
//

#include <iostream>
#include "etat.h"

Etat::Etat(string name)
{
    this->name = name;
}


Etat::~Etat() {}

void Etat::print() const
{

}

void Etat::printTransition(string symbole, string from, string to) const
{
    cout << from << " - " << to << " avec s:" << symbole << endl;
}