#include "e9.h"
#include "e4.h"

E9::E9(string name) : Etat(name) {}

E9::~E9() {}

bool E9::transition(Automate &automate, Symbole *s) {
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