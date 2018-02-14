//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class E0 : public Etat {
public :
    E0(string name);
    ~E0();
    void print() const;

    enum Statut transition(Automate & automate, Symbole *s);
};

