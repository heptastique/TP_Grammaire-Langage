# include "e8.h"

E8::E8(string name) : Etat(name)
{

}

E8::~E8()
{

}

bool E8::transition(Automate & automate, Symbole * symbole)
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
