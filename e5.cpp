#include <iostream>
#include "e5.h"
#include "e3.h"
#include "e2.h"
#include "e8.h"

E5::E5(string name) : Etat(name) {}

E5::~E5() {}

int E5::transition(Automate & automate, Symbole * s)
{
	#ifdef DEBUG
	cout << "Entrée dans l'état 5.\n";
	#endif
	switch(*s) {
		case INT:
			automate.decalage(s, new E3("E3"));
			break;
		case OPENPAR:
			automate.decalage(s, new E2("E2"));
			break;
		case EXPR:
			automate.decalage(s, new E8("E8"));
			break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return false;
}
