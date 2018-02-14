# include "e7.h"
# include "e5.h"

E7::E7(string name) : Etat(name)
{

}

E7::~E7()
{

}

bool E7::transition(Automate & automate, Symbole * symbole)
{
	switch(*symbole)
	{
		case PLUS:
			automate.reduction(1, symbole);
			break;
		case MULT:
			automate.decalage(symbole, new E5("etat5"));
			break;
		case CLOSEPAR:
			automate.reduction(1, symbole);
			break;
		case FIN:
			automate.reduction(1, symbole);
			break;
		default:
			break;
	}
}
