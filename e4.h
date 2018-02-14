//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class E4 : public Etat {
public :
    E4(string name);
    ~E4();
    void print() const;
    bool transition(Automate &automate, Symbole *s);
};

