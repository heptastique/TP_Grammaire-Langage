//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e5.h"
#include "e3.h"
#include "e2.h"
#include "e8.h"


E5::E5(string name) : Etat(name){}

E5::~E5() {}

void E5::print() const
{
    Etat::print();
}

bool E5::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            cout << "Erreur: caractere interdit." << endl;
            return true;
        case INT:
            printTransition("INT", "etat5", "etat3");
            automate.decalage(s ,new E3("etat3"));
            break;
        case OPENPAR:
            printTransition("OPENPAR", "etat5", "etat2");
            automate.decalage(s, new E2("etat2"));
            break;
        case EXPR:
            printTransition("EXPR", "etat5", "etat8");
            automate.decalage(s, new E8("etat8"));
            break;
        default:
            cout << "Erreur: mauvaise syntaxe." << endl;
            return true;
    }
    return false;
}

