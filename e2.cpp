//
// Created by Vincent on 14/02/2018.
//

#include "e2.h"
#include "e3.h"
#include "e6.h"

E2::E2(string name) : Etat(name){}

E2::~E2() {}

void E2::print() const
{
    Etat::print();
}

bool E2::transition(Automate &automate, Symbole *s)
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
            automate.decalage(s, new E6("etat6"));
    }
    return false;
}

