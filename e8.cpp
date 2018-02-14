#include "e8.h"
#include "e3.h"

E8::E8(string name) : Etat(name) {}

E8::~E8() {}

bool E8::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.decalage(s, new E3("E3"));
            break;
    }
    return false;
}