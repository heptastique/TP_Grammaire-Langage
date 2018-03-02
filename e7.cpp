#include <iostream>
#include "e7.h"
#include "e5.h"
#include "exprPlus.h"

E7::E7(string name) : Etat(name) {}

E7::~E7() {}

int E7::transition(Automate & automate, Symbole * s)
{
	#ifdef DEBUG
	cout << "Entrée dans l'état 7.\n";
	cout << *s << endl;
	#endif
	Entier *s1;
	Entier *s2;
	ExprPlus *ep;
	switch(*s) {
		case MULT:
			automate.decalage(s, new E5("E5"));
			break;
		case PLUS:
			// On réduit à l'aide de la règle 2 : E -> E + E
			// On réduit de trois états et on ajoute E à la pile de symboles (somme des E et E de la pile des symboles)
			s1 = (Entier*) automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*) automate.popAndDestroySymbol();
			ep = new ExprPlus(s2,s1);
			automate.reduction(3, ep);
			break;
		case CLOSEPAR:
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*)automate.popAndDestroySymbol();
			ep = new ExprPlus(s2, s1);
			automate.reduction(3, ep);
			break;
		case FIN:
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*)automate.popAndDestroySymbol();
			ep = new ExprPlus(s2, s1);
			automate.reduction(3, ep);
			break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return false;
}
