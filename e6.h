#pragma once
#include "debug.h"
#include "etat.h"

class E6 : public Etat {
public:
    E6(string name);
    ~E6();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};