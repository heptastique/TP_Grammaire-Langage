//
// Created by Vincent on 14/02/2018.
//

#include "e5.h"
#include "e3.h"
#include "e2.h"
#include "e8.h"


E5::E5(string name) : Etat(name){}

E5::~E5() {}

void E5::print() const
{
    Etat::print();
}

bool E5::transition(Automate &automate, Symbole *s)
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
            automate.decalage(s, new E8("etat8"));
            break;
    }
    return false;
}

