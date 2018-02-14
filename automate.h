# pragma once

# include <vector>
# include "lexer.h"

using namespace std;

class Etat;

class Automate
{
	public:

		Automate();
		virtual ~Automate();

		// Lecture de la chaine de caracteres entree
		void lecture();

		// Empile un symbole et un etat
		void decalage(Symbole * symbole, Etat * etat);

		void reduction(int n, Symbole * symbole);

	protected:

		void printEtats();
		void printSymboles();

		string chaine;

		vector <Etat *> etats;
		vector <Symbole *> symboles;
};
