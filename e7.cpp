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
            printTransition("MULT", "etat7", "etat5");
            automate.decalage(s, new E5("etat5"));
            break;
        default:
            printTransition("REDUCTION", "depuis 7", "avec default");
            auto s1 = (Expr*) automate.pop();
            automate.pop();
            auto s2 = (Expr*) automate.pop();
            s1->setVal(s1->getVal()+s2->getVal());
            s1->setIdent(5);
            automate.reduction(3, s1);
            break;

    }
    return false;
}

