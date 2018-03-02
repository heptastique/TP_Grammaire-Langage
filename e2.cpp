#include <iostream>
#include "e2.h"
#include "e3.h"
#include "e6.h"

E2::E2(string name) : Etat(name) {}

E2::~E2() {}

int E2::transition(Automate & automate, Symbole * s)
{
	#ifdef DEBUG
	cout << "Entrée dans l'état 2.\n";
	#endif
	switch(*s) {
		case INT:
			automate.decalage(s, new E3("E3"));
			break;
		case OPENPAR:
			automate.decalage(s, new E2("E2"));
			break;
		case EXPR:
            automate.decalage(s, new E6("E6"));
            break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return 0;
}
