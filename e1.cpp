//
// Created by Vincent on 13/02/2018.
//

#include "e1.h"
#include "e4.h"
#include "e5.h"

E1::E1(string name) : Etat(name) {}

E1::~E1() {}

bool E1::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4("E4"));
            break;
        case MULT:
            automate.decalage(s, new E5("E5"));
            break;
        case FIN:
            return true;
            break;
    }
    return false;
}