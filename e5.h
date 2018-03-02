#pragma once
#include "debug.h"
#include "etat.h"

class E5 : public Etat {
public:
    E5(string name);
    ~E5();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};