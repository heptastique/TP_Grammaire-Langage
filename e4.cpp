# include "e4.h"
# include "e2.h"
# include "e3.h"
# include "e7.h"

E4::E4(string name) : Etat(name)
{

}

E4::~E4()
{

}

// Transition
	// A la lecture du Symbole
bool E4::transition(Automate & automate, Symbole * symbole)
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
		// Lecture d'un EXPR
		case EXPR:
			// Decalage vers l'Etat 7
			automate.decalage(symbole, new E7("etat7"));
			break;
		// Sinon
		default:
			break;
	}
}
