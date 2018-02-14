#include "e2.h"
#include "e3.h"
#include "e6.h"

E2::E2(string name) : Etat(name) {}

E2::~E2() {}

bool E2::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3("E3"));
            break;
        case OPENPAR:
            automate.decalage(s, new E2("E2"));
            break;
        case EXPR:
            automate.decalage(s, new E6("E6"));
            break;
    }
    return false;
}