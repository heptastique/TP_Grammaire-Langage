//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class E7 : public Etat {
public :
    E7(string name);
    ~E7();
    void print() const;
    enum Statut transition(Automate &automate, Symbole *s);
};

