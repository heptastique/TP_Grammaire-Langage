# include "e5.h"
# include "e2.h"
# include "e3.h"
# include "e8.h"

E5::E5(string name) : Etat(name)
{

}

E5::~E5()
{

}

// Transition
	// A la lecture du Symbole
bool E5::transition(Automate & automate, Symbole * symbole)
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
			// Decalage vers l'Etat 8
			automate.decalage(symbole, new E8("etat8"));
			break;
		// Sinon
		default:
			break;
	}

	return 0;
}
