#pragma once

#include "etat.h"

class E5 : public Etat {
public:
    E5(string name);
    ~E5();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};
