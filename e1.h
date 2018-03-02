#pragma once
#include "debug.h"
#include "etat.h"

class E1 : public Etat {
public:
    E1(string name);
    ~E1();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};