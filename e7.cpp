//
// Created by Vincent on 14/02/2018.
//

#include "e7.h"
#include "e5.h"
#include "expr.h"


E7::E7(string name) : Etat(name){}

E7::~E7() {}

void E7::print() const
{
    Etat::print();
}

bool E7::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case MULT:
            automate.decalage(s, new E5("etat5"));
            break;
        case PLUS:
            auto s1 = (Expr*) automate.pop();
            automate.pop();
            auto s2 = (Expr*) automate.pop();
            //automate.reduction(3, new ExprPlus(s2,s1));
            break;
    }
    return false;
}

