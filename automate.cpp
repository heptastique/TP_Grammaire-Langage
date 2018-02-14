# include <iostream>
# include "automate.h"

Automate::Automate()
{

}

Automate::~Automate()
{

}

void Automate::lecture()
{
	cin >> chaine;

	Lexer lexer(chaine);

	Symbole * symbole;

	while ( *(symbole = lexer.Consulter()) != FIN)
	{
		symbole->Affiche();
		cout << endl;
		lexer.Avancer();
	}
}

void Automate::decalage(Symbole * symbole, Etat * etat)
{
	symboles.push(symbole);
	etats.push(etat);
}

void Automate::reduction(int n, Symbole * symbole)
{
	symboles.push(symbole);

	for (int i = 0; i < n; i = i + 1)
	{
		delete(etats.top());
		etats.pop();
	}
}
