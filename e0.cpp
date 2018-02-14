//
// Created by Vincent on 14/02/2018.
//
#include <iostream>
#include "e0.h"
#include "e3.h"
#include "e2.h"
#include "e1.h"

E0::E0(string name) : Etat(name){}

E0::~E0() {}

void E0::print() const
{
    Etat::print();
}

enum Statut E0::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            return ERREUR_SYNTAXE;
        case INT:
            printTransition("INT", "etat0", "etat3");
            automate.decalage(s ,new E3("etat3"));
            break;
        case OPENPAR:
            printTransition("OPENPAR", "etat0", "etat2");
            automate.decalage(s, new E2("etat2"));
            break;
        case EXPR:
            printTransition("EXPR", "etat0", "etat1");
            automate.decalage(s, new E1("etat1"));
            break;
        default:
            return ERREUR_GRAMMAIRE;

    }
    return EN_COURS;
}
