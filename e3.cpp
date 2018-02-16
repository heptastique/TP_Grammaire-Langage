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
	// Switch sur le Symbole lu
	switch(*symbole)
	{
		// Lexture de '+'
		case PLUS:
			// Depilage du dernier Symbole
			automate.popSymbole();
			// Reduction
				// Depilage de 1 Etat
				// Creation du symbole EXPR
			automate.reduction(1, new Symbole(7));
			break;
		// Lecture de '*'
		case MULT:
			// Depilage du dernier Symbole
			automate.popSymbole();
			// Reduction
				// Depilage de 1 Etat
				// Creation du symbole EXPR
			automate.reduction(1, new Symbole(7));
			break;
		// Lecture de ')'
		case CLOSEPAR:
			// Depilage du dernier Symbole
			automate.popSymbole();
			// Reduction
				// Depilage de 1 Etat
				// Creation du symbole EXPR
			automate.reduction(1, new Symbole(7));
			break;
		// Lecture de '$'
		case FIN:
			// Depilage du dernier Symbole
			automate.popSymbole();
			// Reduction
				// Depilage de 1 Etat
				// Creation du symbole EXPR
			automate.reduction(1, new Symbole(7));
			break;
		// Sinon
		default:
			break;
	}
}
