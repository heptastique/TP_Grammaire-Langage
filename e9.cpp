# include "e9.h"
# include "e5.h"

E9::E9(string name) : Etat(name)
{

}

E9::~E9()
{

}

// Transition
	// A la lecture du Symbole
bool E9::transition(Automate & automate, Symbole * symbole)
{
	Symbole * lastSymbole;

	// Switch sur le symbole lu
	switch(*symbole)
	{
		// Lexture de '+', '*', ')', '$'
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			// Depilage des 3 derniers Symboles
			delete(automate.popSymbole());
			lastSymbole = automate.popSymbole();
			delete(automate.popSymbole());
			// Reduction selon la regle 4
				// Depilage de 1 Etat
				// Empilage du symbole EXPR
			automate.reduction(3, lastSymbole);
			break;
		// Sinon
		default:
			break;
	}

	return 0;
}
