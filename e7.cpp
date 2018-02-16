# include "e7.h"
# include "e5.h"

E7::E7(string name) : Etat(name)
{

}

E7::~E7()
{

}

// Transition
	// A la lecture du Symbole
bool E7::transition(Automate & automate, Symbole * symbole)
{
	// Switch sur le symbole lu
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
			// Decalage vers l'Etat 5
			automate.decalage(symbole, new E5("etat5"));
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
