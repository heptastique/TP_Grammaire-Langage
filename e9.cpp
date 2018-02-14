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
        case PLUS:
        {
            automate.pop();
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            printReduction(*s1, "etat9", "Fin de parenthse");
            automate.reduction(3, s1);
        }
            break;
        case MULT:
        {
            automate.pop();
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            printReduction(*s1, "etat9", "Fin de parenthse");
            automate.reduction(3, s1);
        }
            break;
        case CLOSEPAR:
        {
            automate.pop();
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            printReduction(*s1, "etat9", "Fin de parenthse");
            automate.reduction(3, s1);
        }
            break;
        case FIN:
        {
            automate.pop();
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            printReduction(*s1, "etat9", "Fin de parenthse");
            automate.reduction(3, s1);
        }
            break;



    }
    return false;
}

