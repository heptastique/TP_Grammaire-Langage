#include <iostream>
#include "e8.h"
#include "e5.h"
#include "exprMult.h"

E8::E8(string name) : Etat(name) {}

E8::~E8() {}

int E8::transition(Automate & automate, Symbole * s)
{
#ifdef DEBUG
	cout << "Entrée dans l'état 8.\n";
	cout << *s << endl;
	#endif
	Entier *s1;
	Entier *s2;
	ExprMult *ep;
	switch(*s) {
		case PLUS:
			// On réduit à l'aide de la règle 2 : E -> E * E
			// On réduit de trois états et on ajoute E à la pile de symboles (produit des E et E de la pile des symboles)
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*)automate.popAndDestroySymbol();
			ep = new ExprMult(s2, s1);
			ep->setIdent(5);
			automate.reduction(3, ep);
			break;
		case MULT:
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*)automate.popAndDestroySymbol();
			ep = new ExprMult(s2, s1);
			ep->setIdent(5);
			automate.reduction(3, ep);
			break;
		case CLOSEPAR:
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*)automate.popAndDestroySymbol();
			ep = new ExprMult(s2, s1);
			ep->setIdent(5);
			automate.reduction(3, ep);
			break;
		case FIN:
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*)automate.popAndDestroySymbol();
			ep = new ExprMult(s2, s1);
			ep->setIdent(5);
			automate.reduction(3, ep);
			break;
		case EXPR:
			s1 = (Entier*)automate.popAndDestroySymbol();
			automate.popAndDestroySymbol();
			s2 = (Entier*)automate.popAndDestroySymbol();
			ep = new ExprMult(s2, s1);
			ep->setIdent(5);
			automate.reduction(3, ep);
			break;
		case ERREUR:
			return 2;
		default:
			return 3;
	}
	return false;
}
