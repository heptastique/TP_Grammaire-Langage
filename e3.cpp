#include "e3.h"

E3::E3(string name) : Etat(name) {}

E3::~E3() {}

bool E3::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            Symbole * s1 = automate.pop();
            s1->setIdent(5);
            automate.reduction(1, s1);
            break;
        default:
            break;
    }
    return false;
}