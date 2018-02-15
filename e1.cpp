# include "e1.h"
# include "e4.h"
# include "e5.h"

E1::E1(string name) : Etat(name)
{

}

E1::~E1()
{

}

bool E1::transition(Automate & automate, Symbole * symbole)
{
	cout << "Etat 1" << endl;
	symbole->print();

	switch(*symbole)
	{
		case PLUS:
			cout << "Etat 1 Symbole +" << endl;
			automate.decalage(symbole, new E4("etat4"));
			break;
		case MULT:
			automate.decalage(symbole, new E5("etat5"));
			break;
		default:
			break;
	}
}
