//
// Created by Vincent on 14/02/2018.
//

#include "e9.h"



E9::E9(string name) : Etat(name){}

E9::~E9() {}

void E9::print() const
{
    Etat::print();
}

bool E9::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
    }
    return false;
}

