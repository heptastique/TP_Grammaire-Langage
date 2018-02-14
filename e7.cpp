//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e7.h"
#include "e5.h"
#include "expr.h"


E7::E7(string name) : Etat(name) {}

E7::~E7() {}

void E7::print() const
{
    Etat::print();
}

enum Statut E7::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
        case ERREUR:
            return ERREUR_SYNTAXE;
        case MULT:
            printTransition("MULT", "etat7", "etat5");
            automate.decalage(s, new E5("etat5"));
            break;
        case PLUS:
        {
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            auto s2 = (Expr *) automate.pop();
            s1->setVal(s1->getVal() + s2->getVal());
            s1->setIdent(5);
            printReduction(*s1, "etat7", "Operation plus");
            automate.reduction(3, s1);
        }
            break;
        case CLOSEPAR:
        {
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            auto s2 = (Expr *) automate.pop();
            s1->setVal(s1->getVal() + s2->getVal());
            s1->setIdent(5);
            printReduction(*s1, "etat7", "Operation plus");
            automate.reduction(3, s1);
        }
            break;
        case FIN:
        {
            auto s1 = (Expr *) automate.pop();
            automate.pop();
            auto s2 = (Expr *) automate.pop();
            s1->setVal(s1->getVal() + s2->getVal());
            s1->setIdent(5);
            printReduction(*s1, "etat7", "Operation plus");
            automate.reduction(3, s1);
        }
            break;
        default:
            return ERREUR_GRAMMAIRE;

    }
    return EN_COURS;
}

