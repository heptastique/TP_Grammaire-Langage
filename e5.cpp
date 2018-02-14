#include "e5.h"
#include "e2.h"
#include "e3.h"

E5::E5(string name) : Etat(name) {}

E5::~E5() {}

bool E5::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3("E3"));
            break;
        case OPENPAR:
            automate.decalage(s, new E2("E2"));
            break;
    }
    return false;
}