//
// Created by Vincent on 14/02/2018.
//

#include <iostream>
#include "e3.h"

E3::E3(string name) : Etat(name){}

E3::~E3() {}

void E3::print() const
{
    Etat::print();
}

bool E3::transition(Automate &automate, Symbole *s)
{
    switch(*s)
    {
        case ERREUR:
            cout << "Erreur: caractere interdit." << endl;
            return true;
        case PLUS:
        {
            Symbole * s1 = automate.pop();
            s1->setIdent(5);
            printReduction(*s1, "etat3", "Lecture d'une 'val'");
            automate.reduction(1,s1);
        }
            break;
        case MULT:
        {
            Symbole * s1 = automate.pop();
            s1->setIdent(5);
            printReduction(*s1, "etat3", "Lecture d'une 'val'");
            automate.reduction(1,s1);
        }
            break;
        case CLOSEPAR:
        {
            Symbole * s1 = automate.pop();
            s1->setIdent(5);
            printReduction(*s1, "etat3", "Lecture d'une 'val'");
            automate.reduction(1,s1);
        }
            break;
        case FIN:
        {
            Symbole * s1 = automate.pop();
            s1->setIdent(5);
            printReduction(*s1, "etat3", "Lecture d'une 'val'");
            automate.reduction(1,s1);
        }
            break;
        default:
            cout << "Erreur: mauvaise syntaxe." << endl;
            return true;
    }
    return false;
}
