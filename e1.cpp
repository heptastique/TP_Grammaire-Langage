#include <iostream>
#include "e1.h"
#include "e4.h"
#include "e5.h"

E1::E1(string name) : Etat(name) {}

E1::~E1() {}

int E1::transition(Automate & automate, Symbole * s)
{
	#ifdef DEBUG
	cout << "Entrée dans l'état 1.\n";
	cout << *s << endl;
	#endif
	switch(*s) {
		case PLUS:
			automate.decalage(s, new E4("E4"));
			break;
		case MULT:
			automate.decalage(s, new E5("E5"));
			break;
		case FIN:
			return 1;
			break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return 0;
}
