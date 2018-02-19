#include "e0.h"
#include "e1.h"
#include "e2.h"
#include "e3.h"

E0::E0(string name) : Etat(name) {}

E0::~E0() {}

bool E0::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3("E3"));
            break;
        case OPENPAR:
            automate.decalage(s, new E2("E2"));
            break;
        case EXPR:
            automate.decalage(s, new E1("E1"));
            break;
        default:
            break;
    }
    return false;
}