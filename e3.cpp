# include "e3.h"
# include "symbole.h"

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
			//cout << "Etat 3 Symbole +" << endl;
			automate.popSymbole();
			automate.reduction(1, new Symbole(7));
			break;
		case MULT:
			automate.popSymbole();
			automate.reduction(1, new Symbole(7));
			break;
		case CLOSEPAR:
			automate.popSymbole();
			automate.reduction(1, new Symbole(7));
			break;
		case FIN:
			automate.popSymbole();
			automate.reduction(1, new Symbole(7));
			break;
		default:
			break;
	}
}
