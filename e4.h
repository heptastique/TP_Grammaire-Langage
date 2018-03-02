#pragma once
#include "debug.h"
#include "etat.h"

class E4 : public Etat {
public:
    E4(string name);
    ~E4();
    void print() const;
    int transition(Automate & automate, Symbole * s);
};
