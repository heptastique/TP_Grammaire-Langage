//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e9.h"
#include "expr.h"


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
        case ERREUR:
            cout << "Erreur: caractere interdit" << endl;
            return true;
        default:
            printTransition("REDUCTION", "depuis 9", "avec default");
            automate.pop();
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            automate.reduction(3, s1);
    }
    return false;
}

