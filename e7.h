#pragma once
#include "debug.h"
#include "etat.h"

class E7 : public Etat {
public:
    E7(string name);
    ~E7();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};