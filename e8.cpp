//
// Created by Vincent on 14/02/2018.
//
#include <iostream>
#include "e8.h"
#include "expr.h"


E8::E8(string name) : Etat(name){}

E8::~E8() {}

void E8::print() const
{
    Etat::print();
}

enum Statut E8::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            return ERREUR_SYNTAXE;
        case PLUS:
        {
            auto s1 = (Expr*) automate.pop();
            automate.pop();
            auto s2 = (Expr*) automate.pop();
            s1->setVal(s1->getVal()*s2->getVal());
            s1->setIdent(5);
            printReduction(*s1, "etat8", "Operation mult");
            automate.reduction(3, s1);
        }
            break;
        case MULT:
        {
            auto s1 = (Expr*) automate.pop();
            automate.pop();
            auto s2 = (Expr*) automate.pop();
            s1->setVal(s1->getVal()*s2->getVal());
            s1->setIdent(5);
            printReduction(*s1, "etat8", "Operation mult");
            automate.reduction(3, s1);
        }
            break;
        case CLOSEPAR:
        {
            auto s1 = (Expr*) automate.pop();
            automate.pop();
            auto s2 = (Expr*) automate.pop();
            s1->setVal(s1->getVal()*s2->getVal());
            s1->setIdent(5);
            printReduction(*s1, "etat8", "Operation mult");
            automate.reduction(3, s1);
        }
            break;
        case FIN:
        {
            auto s1 = (Expr*) automate.pop();
            automate.pop();
            auto s2 = (Expr*) automate.pop();
            s1->setVal(s1->getVal()*s2->getVal());
            s1->setIdent(5);
            printReduction(*s1, "etat8", "Operation mult");
            automate.reduction(3, s1);
        }
            break;
        default:
            return ERREUR_GRAMMAIRE;
    }
    return EN_COURS;
}

