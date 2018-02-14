# include "e2.h"
# include "e3.h"
# include "e6.h"

E2::E2(string name) : Etat(name)
{

}

E2::~E2()
{

}

bool E2::transition(Automate & automate, Symbole * symbole)
{
	switch(*symbole)
	{
		case INT:
			automate.decalage(symbole, new E3("etat3"));
			break;
		case OPENPAR:
			automate.decalage(symbole, new E2("etat2"));
			break;
		case EXPR:
			automate.decalage(symbole, new E6("etat6"));
		default:
			break;
	}
}
