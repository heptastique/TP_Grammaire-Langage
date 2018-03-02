#pragma once
#include "debug.h"
#include "etat.h"

class E8 : public Etat {
public:
    E8(string name);
    ~E8();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};