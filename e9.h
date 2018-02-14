#pragma once

#include "etat.h"

class E9 : public Etat {
public:
    E9(string name);
    ~E9();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
};
