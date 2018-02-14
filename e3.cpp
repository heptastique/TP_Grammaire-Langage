# include "e3.h"

E3::E3(string name) : Etat(name)
{

}

E3::~E3()
{

}

bool E3::transition(Automate & automate, Symbole * symbole)
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
