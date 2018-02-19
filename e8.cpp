# include "e8.h"
# include "e5.h"

E8::E8(string name) : Etat(name)
{

}

E8::~E8()
{

}

// Transition
	// A la lecture du Symbole
bool E8::transition(Automate & automate, Symbole * symbole)
{
	Entier * lastSymbole1;
	Entier * lastSymbole2;

	// Switch sur le symbole lu
	switch(*symbole)
	{
		// Lexture de '+', '*', ')', '$'
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			// Depilage des 3 derniers Symboles
			lastSymbole1 = (Entier *) automate.popSymbole();
			delete(automate.popSymbole());
			lastSymbole2 = (Entier *) automate.popSymbole();
			// Modification de la valeur de INT
			lastSymbole2->setValeur(lastSymbole1->getValeur() * lastSymbole2->getValeur());
			// Reduction selon la regle 3
				// Depilage de 1 Etat
				// Empilage du symbole EXPR
			automate.reduction(3, lastSymbole2);
			delete(lastSymbole1);
			break;
		// Sinon
		default:
			break;
	}

	return 0;
}
