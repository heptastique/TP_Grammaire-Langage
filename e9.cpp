#include <iostream>
#include "e9.h"
#include "e5.h"

E9::E9(string name) : Etat(name) {}

E9::~E9() {}

int E9::transition(Automate & automate, Symbole * s)
{
	#ifdef DEBUG
	cout << "Entrée dans l'état 9.\n";
	#endif
	
	Entier *s1;
	switch(*s) {
		case PLUS:
			// On réduit à l'aide de la règle 4 : E -> ( E )
			// On réduit de trois états et on ajoute E à la pile de symboles
			automate.popAndDestroySymbol();
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			automate.reduction(3, s1);
			break;
		case MULT:
			automate.popAndDestroySymbol();
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			automate.reduction(3, s1);
			break;
		case CLOSEPAR:
			automate.popAndDestroySymbol();
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			automate.reduction(3, s1);
			break;
		case FIN:
			automate.popAndDestroySymbol();
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			automate.reduction(3, s1);
			break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return false;
}
