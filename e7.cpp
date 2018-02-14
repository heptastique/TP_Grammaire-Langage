#include "e7.h"
#include "e5.h"
#include "e2.h"

E7::E7(string name) : Etat(name) {}

E7::~E7() {}

bool E7::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.reduction(1, s);
            break;
        case MULT:
            automate.decalage(s, new E5("E5"));
            break;
        case CLOSEPAR:
        case FIN:
            automate.decalage(s, new E2("E2"));
            break;
    }
    return false;
}