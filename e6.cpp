# include "e6.h"
# include "e4.h"
# include "e5.h"
# include "e9.h"

E6::E6(string name) : Etat(name)
{

}

E6::~E6()
{

}

bool E6::transition(Automate & automate, Symbole * symbole)
{
	switch(*symbole)
	{
		case PLUS:
			automate.decalage(symbole, new E4("etat4"));
			break;
		case MULT:
			automate.decalage(symbole, new E5("etat5"));
			break;
		case CLOSEPAR:
			automate.decalage(symbole, new E9("etat9"));
			break;
		default:
			break;
	}
}
