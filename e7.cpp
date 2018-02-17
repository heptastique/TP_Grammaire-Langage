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
	Symbole * lastSymbole;
	Symbole * s2;

	Entier * e1;
	Entier * e2;

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
			e1 = (Entier *) automate.popSymbole();
			automate.popSymbole();
			e2 = (Entier *) automate.popSymbole();
			e2->setValeur(e1->getValeur() + e2->getValeur());
			// Reduction
				// Depilage de 3 Etats
				// Creation du symbole EXPR
			automate.reduction(3, e2);
			break;
		// Sinon
		default:
			break;
	}
}
