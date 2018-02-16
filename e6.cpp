# include "e6.h"
# include "e4.h"
# include "e5.h"
# include "e9.h"

E6::E6(string name) : Etat(name)
{

}

E6::~E6()
{

}

// Transition
	// A la lecture du Symbole
bool E6::transition(Automate & automate, Symbole * symbole)
{
	// Switch sur le Symbole lu
	switch(*symbole)
	{
		// Lecture de '+'
		case PLUS:
			// Decalage vers l'Etat 4
			automate.decalage(symbole, new E4("etat4"));
			break;
		// Lecture de '*'
		case MULT:
			// Decalage vers l'Etat 5
			automate.decalage(symbole, new E5("etat5"));
			break;
		// Lecture de ')'
		case CLOSEPAR:
			// Decalage vers l'Etat 9
			automate.decalage(symbole, new E9("etat9"));
			break;
		// Sinon
		default:
			break;
	}
}
