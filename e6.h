//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class E6 : public Etat {
public :
    E6(string name);
    ~E6();
    void print() const;
    enum Statut transition(Automate &automate, Symbole *s);
};

