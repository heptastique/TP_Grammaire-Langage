#pragma once
#include "debug.h"
#include "etat.h"

class E3 : public Etat {
public:
    E3(string name);
    ~E3();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};