#include <iostream>
#include "e0.h"
#include "e3.h"
#include "e2.h"
#include "e1.h"

E0::E0(string name) : Etat(name) {}

E0::~E0() {}

int E0::transition(Automate & automate, Symbole * s)
{
	#ifdef DEBUG
	cout << "Entrée dans l'état 0.\n";
	cout << *s << endl;
	#endif
	switch(*s) {
		case INT:
			automate.decalage(s, new E3("E3"));
			break;
		case OPENPAR:
			automate.decalage(s, new E2("E2"));
			break;
		case EXPR:
            automate.decalage(s, new E1("E1"));
            break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return 0;
}
