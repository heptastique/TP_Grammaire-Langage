//
// Created by Vincent on 13/02/2018.
//
#pragma once

#include "etat.h"

class E1 : public Etat {
public :
    E1(string name);
    ~E1();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};



