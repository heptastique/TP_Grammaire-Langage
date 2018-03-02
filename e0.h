#pragma once
#include "debug.h"
#include "etat.h"

class E0 : public Etat {
public:
    E0(string name);
    ~E0();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};