#pragma once
#include "debug.h"
#include "etat.h"

class E2 : public Etat {
public:
    E2(string name);
    ~E2();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};