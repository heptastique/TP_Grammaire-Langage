#include "e4.h"
#include "e3.h"
#include "e2.h"
#include "e7.h"

E4::E4(string name) : Etat(name) {}

E4::~E4() {}

bool E4::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3("E3"));
            break;
        case OPENPAR:
            automate.decalage(s, new E2("E2"));
            break;
        case EXPR:
            automate.decalage(s, new E7("E7"));
            break;
    }
    return false;
}