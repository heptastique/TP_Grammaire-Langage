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
		case INT:
			automate.decalage(symbole, new E3("etat3"));
			break;
		case OPENPAR:
			automate.decalage(symbole, new E2("etat2"));
			break;
		case EXPR:
			automate.decalage(symbole, new E1("etat1"));
			break;
		default:
			break;
	}
}
