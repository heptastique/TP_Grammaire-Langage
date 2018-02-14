//
// Created by Vincent on 14/02/2018.
//
#pragma once

#include "etat.h"

class Automate;
class E9 : public Etat {
public :
    E9(string name);
    ~E9();
    void print() const;
    bool transition(Automate &automate, Symbole *s);
};

