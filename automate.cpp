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

// Affiche la pile des Etats
void Automate::printEtats()
{
	cout << "Etats : {";

	for (int i = 0; i < etats.size(); i = i + 1)
	{
		etats[i]->print();
		cout << ", ";
	}

	cout << "}" << endl;
}

// Affiche la pile des Symboles
void Automate::printSymboles()
{
	cout << "Symboles : {";

	for (int i = 0; i < symboles.size(); i = i + 1)
	{
		symboles[i]->print();
		cout << ", ";
	}

	cout << "}" << endl;
}

// Evaluation de la chaine de l'utilisateur
void Automate::lecture()
{
	// Lecture de la chaine de l'utilisateur
	cin >> chaine;

	// Initialisation du lexer
	lexer = new Lexer(chaine);

	// Symbole de la chaine en cours de lecture
	Symbole * symbole;

	// Creation de l'etat initial
	Etat * e0 = new E0("etat0");
	// Ajout de l'etat initial a la pile des Etats
	etats.push_back(e0);

	/*
	while ( *(symbole = lexer->consulter()) != FIN)
	{
		symbole->affiche();
		cout << endl;
		lexer->avancer();
	}
	*/

	bool fin = 0;

	while (fin != 1)
	{
		//printEtats();
		//printSymboles();

		// Lecture du prochain symbole de la chaine
		symbole = lexer->consulter();
		// Transition depuis le dernier Etat de la pile des Etats,
			// En fonction du Symbole lu
		fin = etats.back()->transition(*this, symbole);
	}

	cout << " = " << ((Entier *) symboles.back())->getValeur() << endl;
}

// Decalage
	// Symbole lu
	// Vers l'etat de destination
void Automate::decalage(Symbole * symbole, Etat * etat)
{
	/*
	cout << "Automate Decalage" << endl;
	cout << "	Symbole : ";
 	symbole->print();
	cout << endl;
	cout << "	Etat : ";
	etat->print();
	cout << endl;
	*/

	// Empilage du nouveau symbole
	symboles.push_back(symbole);
	// Empilage de l'etat de destination
	etats.push_back(etat);

	// Si le symbole lu est terminal
	if ((int) * symbole < 5)
	{
		// Avancer la tete de lecture du lexer
		lexer->avancer();
	}
	// Sinon (le symbole n'est pas terminal (exemple : EXPR))
	// On ne lit pas de nouveau symbole
}

// Reduction
	// Nombre d'Etats a depiler
	// Symbole cree par la reduction
void Automate::reduction(int n, Symbole * symbole)
{
	/*
	cout << "Automate Reduction" << endl;
	cout << "	Nombre d'Etats : " << n << endl;
	cout << "	Symbole : ";
 	symbole->print();
	cout << endl;
	*/

	//printEtats();

	// Pour le nombre d'Etats a depiler
	for (int i = 0; i < n; i = i + 1)
	{
		//cout << "Depilage de l'Etat :" << endl;
		//etats.back()->print();
		//cout << endl;

		// Depiler le dernier Etat de la pile des Etats
		delete(etats.back());
		etats.pop_back();

		//printEtats();
	}

	//cout << " 1 : " << endl;
	//printEtats();

	//cout << "BACK :" << endl;
	//etats.back()->print();

	// Si la pile des Etats n'est pas vide
	// (Securite, probablement inutile)
	if (etats.size() != 0)
	{
		// Transition depuis le dernier Etat de la pile des Etats,
			// En fonction du Symbole cree par la reduction
		etats.back()->transition(*this, symbole);
	}

	//cout << " 2 : " << endl;
	//printEtats();

	//cout << "BACK :" << endl;
	//etats.back()->print();
}

// Depiler le dernier Symbole de la pile des Symboles
Symbole * Automate::popSymbole()
{
	//cout << "Depilage du Symbole :" << endl;
	//symboles.back()->print();
	//cout << endl;

	// Depiler le dernier Symbole de la pile des Symboles
	Symbole * symbole = symboles.back();

	symboles.pop_back();

	return symbole;
}
