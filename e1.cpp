//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e1.h"
#include "e4.h"
#include "e5.h"


E1::E1(string name) : Etat(name){}

E1::~E1() {}

void E1::print() const
{
    Etat::print();
}

bool E1::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case PLUS:
            automate.decalage(s, new E4("etat4"));
            break;
        case MULT:
            automate.decalage(s, new E5("etat5"));
            break;
        case FIN:
            cout << "THIS IS THE END" << endl;
            return false;
    }
    return false;
}

