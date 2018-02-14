//
// Created by Vincent on 14/02/2018.
//

#include "e3.h"

E3::E3(string name) : Etat(name){}

E3::~E3() {}

void E3::print() const
{
    Etat::print();
}

bool E3::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case INT:
        default:
            Symbole * s1 = automate.pop();
            automate.reduction(1,s1);
            break;
    }
    return false;
}
