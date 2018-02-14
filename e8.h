//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class E8 : public Etat {
public :
    E8(string name);
    ~E8();
    void print() const;
    enum Statut transition(Automate &automate, Symbole *s);
};

