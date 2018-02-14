//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class E2 : public Etat {
public :
    E2(string name);
    ~E2();
    void print() const;
    bool transition(Automate &automate, Symbole *s);
};

