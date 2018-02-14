//
// Created by Vincent on 13/02/2018.
//
#pragma  once

#include "Symbole.h"
#include "automate.h"


class Etat {
public:
    Etat(string name);
    virtual ~Etat();
    void print() const;
    void printTransition(string symbole, string from, string to) const;
    virtual bool transition(Automate & automate, Symbole * s) = 0;
protected:
    string name;
};


