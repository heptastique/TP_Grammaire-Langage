#include "e8.h"
#include "e3.h"

E8::E8(string name) : Etat(name) {}

E8::~E8() {}

bool E8::transition(Automate &automate, Symbole *s) {
    Entier * s1;
    Entier * s2;
    
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            s1 = (Entier *) automate.pop();
            delete(automate.pop());
            s2 = (Entier *) automate.pop();
            s2->setVal(s1->getVal() * s2->getVal());
            automate.reduction(3, s2);
            delete(s2);
            break;
        default:
            break;
    }
    return false;
}