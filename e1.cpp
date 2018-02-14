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

enum Statut E1::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            return ERREUR_SYNTAXE;
        case PLUS:
            printTransition("PLUS", "etat1", "etat4");
            automate.decalage(s, new E4("etat4"));
            break;
        case MULT:
            printTransition("MULT", "etat1", "etat5");
            automate.decalage(s, new E5("etat5"));
            break;
        case FIN:
            return TERMINE;
        default:
            return ERREUR_GRAMMAIRE;
    }
    return EN_COURS;
}

