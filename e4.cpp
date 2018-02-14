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

bool E4::transition(Automate & automate, Symbole * symbole)
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
			automate.decalage(symbole, new E7("etat7"));
			break;
		default:
			break;
	}
}
