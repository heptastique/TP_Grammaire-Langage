#pragma once

#include "etat.h"

class E6 : public Etat {
public:
    E6(string name);
    ~E6();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};
