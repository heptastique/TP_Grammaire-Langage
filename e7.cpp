#include "e7.h"
#include "e5.h"
#include "expr.h"

E7::E7(string name) : Etat(name) {}

E7::~E7() {}

bool E7::transition(Automate &automate, Symbole *s) {
    Entier * s1;
    Entier * s2;
    
    switch (*s) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            s1 = (Entier *) automate.pop();
            delete(automate.pop());
            s2 = (Entier *) automate.pop();
            s1->setVal(s1->getVal()+s2->getVal());
            s1->setIdent(5);
            automate.reduction(3, s1);
            delete(s1);
            break;
        case MULT:
            automate.decalage(s, new E5("E5"));
            break;
        default:
            break;
    }
    return false;
}