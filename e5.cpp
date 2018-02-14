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

bool E5::transition(Automate & automate, Symbole * symbole)
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
			automate.decalage(symbole, new E8("etat8"));
			break;
		default:
			break;
	}
}
