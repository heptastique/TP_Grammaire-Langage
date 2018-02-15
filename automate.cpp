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
			symbole->print();
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

	lexer = new Lexer(chaine);

	Symbole * symbole;

	Etat * e0 = new E0("etat0");
	etats.push_back(e0);

	/*while ( *(symbole = lexer->consulter()) != FIN)
	{
		symbole->affiche();
		cout << endl;
		lexer->avancer();
	}*/

	printEtats();
	printSymboles();

	symbole = lexer->consulter();
	etats.back()->transition(*this, symbole);

	printEtats();
	printSymboles();

	symbole = lexer->consulter();
	etats.back()->transition(*this, symbole);

	printEtats();
	printSymboles();

	symbole = lexer->consulter();
	etats.back()->transition(*this, symbole);

	printEtats();
	printSymboles();

	symbole = lexer->consulter();
	etats.back()->transition(*this, symbole);

	printEtats();
	printSymboles();

	symbole = lexer->consulter();
	etats.back()->transition(*this, symbole);

	printEtats();
	printSymboles();

	symbole = lexer->consulter();
	etats.back()->transition(*this, symbole);

	printEtats();
	printSymboles();
}

void Automate::decalage(Symbole * symbole, Etat * etat)
{
	cout << "Automate Decalage" << endl;
	cout << "	Symbole :"<< endl;
 	symbole->print();
	cout << endl;
	cout << "	Etat :" << endl;
	etat->print();
	cout << endl;

	symboles.push_back(symbole);
	etats.push_back(etat);

	if ((int) * symbole < 5)
	{
		lexer->avancer();
	}
}

void Automate::reduction(int n, Symbole * symbole)
{
	cout << "Automate Reduction" << endl;
	cout << "	Nombre d'Etats : " << n << endl;
	cout << "	Symbole :"<< endl;
 	symbole->print();
	cout << endl;

	for (int i = 0; i < n; i = i + 1)
	{
		delete(etats.back());
		etats.pop_back();
	}

	//symboles.push_back(symbole);

	if (etats.size() != 0)
	{
		//cout << "Automate Transition" << endl;

		etats.back()->transition(*this, symbole);
	}
}

void Automate::popSymbole()
{
	//cout << "Automate Pop Symbole" << endl;

	delete(symboles.back());
	symboles.pop_back();
}
