# include <iostream>

# include "automate.h"
# include "etat.h"
# include "e0.h"

Automate::Automate()
{

}

Automate::~Automate()
{

}

void Automate::printEtats()
{
	cout << "Etats : {";

	int i = 0;

	if (etats.size() != 0)
	{
		Etat * etat = etats[0];

		while (etat != NULL)
		{
			etat->print();
			cout << ", ";
			i = i + 1;
			etat = etats[i];
		}
	}

	cout << "}" << endl;
}

void Automate::printSymboles()
{
	cout << "Symboles : {";

	int i = 0;

	if (symboles.size() != 0)
	{
		Symbole * symbole = symboles[0];

		while (symbole != NULL)
		{
			symbole->affiche();
			cout << ", ";
			i = i + 1;
			symbole = symboles[i];
		}
	}

	cout << "}" << endl;
}

void Automate::lecture()
{
	cin >> chaine;

	Lexer lexer(chaine);

	Symbole * symbole;
	E0 * e0 = new E0("etat0");

	/*while ( *(symbole = lexer.consulter()) != FIN)
	{
		symbole->affiche();
		cout << endl;
		lexer.avancer();
	}*/

	printEtats();
	printSymboles();

	symbole = lexer.consulter();
	e0->transition(*this, symbole);
	lexer.avancer();

	printEtats();
	printSymboles();

	symbole = lexer.consulter();
	etats.back()->transition(*this, symbole);
	lexer.avancer();

	printEtats();
	printSymboles();

	symbole = lexer.consulter();
	etats.back()->transition(*this, symbole);
	lexer.avancer();

	printEtats();
	printSymboles();
}

void Automate::decalage(Symbole * symbole, Etat * etat)
{
	symboles.push_back(symbole);
	etats.push_back(etat);
}

void Automate::reduction(int n, Symbole * symbole)
{
	for (int i = 0; i < n; i = i + 1)
	{
		delete(etats.back());
		etats.pop_back();
	}

	if (etats.size() != 0)
	{
		etats.back()->transition(*this, symbole);
	}
}
