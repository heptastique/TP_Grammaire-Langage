# include "e9.h"

E9::E9(string name) : Etat(name)
{

}

E9::~E9()
{

}

bool E9::transition(Automate & automate, Symbole * symbole)
{
	switch(*symbole)
	{
		case PLUS:
			automate.reduction(1, symbole);
			break;
		case MULT:
			automate.reduction(1, symbole);
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
