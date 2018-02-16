# include "e0.h"
# include "e1.h"
# include "e2.h"
# include "e3.h"

E0::E0(string name) : Etat(name)
{

}

E0::~E0()
{

}

bool E0::transition(Automate & automate, Symbole * symbole)
{
	switch(*symbole)
	{
		// Lecture d'un INT
		case INT:
			// On decale vers l'Etat 3
			automate.decalage(symbole, new E3("etat3"));
			break;
		// Lecture de '('
		case OPENPAR:
			// On decale vers l'Etat 2
			automate.decalage(symbole, new E2("etat2"));
			break;
		// Lecture d'une EXPR
		case EXPR:
			// On decale vers l'Etat 2
			automate.decalage(symbole, new E1("etat1"));
			break;
		default:
			break;
	}
}
