//
// Created by Vincent on 14/02/2018.
//
#include "e0.h"
#include "e3.h"

E0::E0(string name) : Etat(name){}

E0::~E0() {}

void E0::print() const
{
    Etat::print();
}

bool E0::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        /*case INT:
            automate->decalage(s ,new E3("etat3"));*/
    }
    return true;
}
