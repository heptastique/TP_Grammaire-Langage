#include <iostream>
#include "e3.h"
#include "exprPlus.h"

E3::E3(string name) : Etat(name) {}

E3::~E3() {}

int E3::transition(Automate & automate, Symbole * s)
{
	#ifdef DEBUG
	cout << "Entrée dans l'état 3.\n";
	#endif
	Symbole * s1;
	switch(*s) {
		case PLUS:
			// On réduit à l'aide de la règle 3 : E -> val
			// On réduit d'un état et on ajoute E à la pile de symboles à la place de val
			s1 = automate.popAndDestroySymbol();
			s1->setIdent(5);
			automate.reduction(1, s1);
			break;
		case MULT:
			s1 = automate.popAndDestroySymbol();
			s1->setIdent(5);
			automate.reduction(1, s1);
			break;
		case CLOSEPAR:
			s1 = automate.popAndDestroySymbol();
			s1->setIdent(5);
			automate.reduction(1, s1);
			break;
		case FIN:
			s1 = automate.popAndDestroySymbol();
			s1->setIdent(5);
			automate.reduction(1, s1);
			break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return false;
}
