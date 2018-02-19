//
// Created by Vincent on 13/02/2018.
//

#include "etat.h"

Etat::Etat(string name) {
    this->name = name;
}

bool Etat::transition(Automate & automate, Symbole * s) {
    return false;
}

string Etat::getName() {
    return name;
}

Etat::~Etat() {}