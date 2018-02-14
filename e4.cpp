//
// Created by Vincent on 14/02/2018.
//

#include "e4.h"
#include "e3.h"
#include "e2.h"
#include "e7.h"

E4::E4(string name) : Etat(name){}

E4::~E4() {}

void E4::print() const
{
    Etat::print();
}

bool E4::transition(Automate &automate, Symbole *s)
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
            automate.decalage(s, new E7("etat7"));
    }
    return false;
}

