# include "e3.h"
# include "symbole.h"

E3::E3(string name) : Etat(name)
{

}

E3::~E3()
{

}


// Transition
	// A la lecture du Symbole
bool E3::transition(Automate & automate, Symbole * symbole)
{
	Symbole * lastSymbole;

	// Switch sur le Symbole lu
	switch(*symbole)
	{
		// Lexture de '+', '*', ')', '$'
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			// Depilage du dernier Symbole
			lastSymbole = automate.popSymbole();
			// Modification du Symbole en EXPR
			lastSymbole->setId(7);
			// Reduction selon la regle 5
				// Depilage de 1 Etat
				// Empilage du symbole EXPR
			automate.reduction(1, lastSymbole);
			break;
		// Sinon
		default:
			break;
	}

	return 0;
}
