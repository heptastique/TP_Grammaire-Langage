//
// Created by Vincent on 14/02/2018.
//
#include "e8.h"


E8::E8(string name) : Etat(name){}

E8::~E8() {}

void E8::print() const
{
    Etat::print();
}

bool E8::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
    }
    return false;
}

