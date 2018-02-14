//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e2.h"
#include "e3.h"
#include "e6.h"

E2::E2(string name) : Etat(name){}

E2::~E2() {}

void E2::print() const
{
    Etat::print();
}

enum Statut E2::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            return ERREUR_SYNTAXE;
        case INT:
            printTransition("INT", "etat2", "etat3");
            automate.decalage(s ,new E3("etat3"));
            break;
        case OPENPAR:
            printTransition("OPENPAR", "etat2", "etat2");
            automate.decalage(s, new E2("etat2"));
            break;
        case EXPR:
            printTransition("EXPR", "etat2", "etat6");
            automate.decalage(s, new E6("etat6"));
            break;
        default:
            return ERREUR_GRAMMAIRE;
    }
    return EN_COURS;
}

