# include "e1.h"
# include "e4.h"
# include "e5.h"

E1::E1(string name) : Etat(name)
{

}

E1::~E1()
{

}

// Transition
	// A la lecture du Symbole
bool E1::transition(Automate & automate, Symbole * symbole)
{
	// Switch sur le Symbole lu
	symbole->print();

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
		// Sinon
		default:
			break;
	}
}
