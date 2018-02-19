#include "e9.h"
#include "e4.h"

E9::E9(string name) : Etat(name) {}

E9::~E9() {}

bool E9::transition(Automate &automate, Symbole *s) {
    
    Symbole * s1;
    
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            delete(automate.pop());
            s1 = automate.pop();
            delete(automate.pop());
            automate.reduction(3, s1);
            break;
        default:
            break;
    }
    return false;
}