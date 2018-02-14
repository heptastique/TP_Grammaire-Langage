//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e6.h"
#include "e4.h"
#include "e5.h"
#include "e9.h"

E6::E6(string name) : Etat(name){}

E6::~E6() {}

void E6::print() const
{
    Etat::print();
}

bool E6::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            cout << "Erreur: caractere interdit" << endl;
            return true;
        case PLUS:
            printTransition("PLUS", "etat6", "etat4");
            automate.decalage(s, new E4("etat4"));
            break;
        case MULT:
            printTransition("MULT", "etat6", "etat5");
            automate.decalage(s, new E5("etat5"));
            break;
        case CLOSEPAR:
            printTransition("CLOSEPAR", "etat6", "etat9");
            automate.decalage(s, new E9("etat9"));
            break;
        default:
            cout << "Erreur: mauvaise syntaxe." << endl;
            return true;
    }
    return false;
}
