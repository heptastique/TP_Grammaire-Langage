#include "e3.h"

E3::E3(string name) : Etat(name) {}

E3::~E3() {}

bool E3::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(1, s);
            break;
    }
    return false;
}