#pragma once
#include "debug.h"
#include "automate.h"
#include "expr.h"

class Etat {
public:
    Etat(string name);
    virtual ~Etat();
    void print() const;
    virtual int transition(Automate & automate, Symbole * s) = 0;
protected:
    string name;
};
