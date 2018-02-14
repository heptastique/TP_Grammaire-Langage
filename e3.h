//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class E3 : public Etat {
public :
    E3(string name);
    ~E3();
    void print() const;
    bool transition(Automate *automate, Symbole *s);
};

