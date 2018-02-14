//
// Created by Vincent on 14/02/2018.
//
#include "e0.h"
#include "e3.h"
#include "e2.h"
#include "e1.h"

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
        case INT:
            automate.decalage(s ,new E3("etat3"));
            break;
        case OPENPAR:
            automate.decalage(s, new E2("etat2"));
            break;
        case EXPR:
            automate.decalage(s, new E1("etat1"));
            break;

    }
    return false;
}
