//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e4.h"
#include "e3.h"
#include "e2.h"
#include "e7.h"

E4::E4(string name) : Etat(name){}

E4::~E4() {}

void E4::print() const
{
    Etat::print();
}

bool E4::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            cout << "Erreur: caractere interdit." << endl;
            return true;
        case INT:
            printTransition("INT", "etat4", "etat3");
            automate.decalage(s ,new E3("etat3"));
            break;
        case OPENPAR:
            printTransition("OPENPAR", "etat4", "etat2");
            automate.decalage(s, new E2("etat2"));
            break;
        case EXPR:
            printTransition("EXPR", "etat4", "etat7");
            automate.decalage(s, new E7("etat7"));
            break;
        default:
            cout << "Erreur: mauvaise syntaxe." << endl;
            return true;
    }
    return false;
}

