//
// Created by Vincent on 13/02/2018.
//
#pragma  once

#include "Symbole.h"

class Automate;
class Etat {
public:
    Etat(string name);
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole * s) = 0;
protected:
    string name;
};


