# include "e2.h"
# include "e3.h"
# include "e6.h"

E2::E2(string name) : Etat(name)
{

}

E2::~E2()
{

}

// Transition
	// A la lecture du Symbole
bool E2::transition(Automate & automate, Symbole * symbole)
{
	// Switch sur le Symbole lu
	switch(*symbole)
	{
		// Lecture d'un INT
		case INT:
			// Decalage vers l'Etat 3
			automate.decalage(symbole, new E3("etat3"));
			break;
		// Lecture de '('
		case OPENPAR:
			// Decalage vers l'Etat 2
			automate.decalage(symbole, new E2("etat2"));
			break;
		// Lecture d'une EXPR
		case EXPR:
			// Decalage vers l'Etat 6
			automate.decalage(symbole, new E6("etat6"));
		default:
			break;
	}

	return 0;
}

