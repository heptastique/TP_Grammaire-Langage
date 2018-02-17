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

		// Evaluation de la chaine entree par l'utilisateur
		void lecture();

		// Decalage
			// Symbole lu
			// Etat destination
		void decalage(Symbole * symbole, Etat * etat);

		// Reduction
			// Nombre d'Etats a depiler
			// Symbole cree
		void reduction(int n, Symbole * symbole);

		// Depiler le dernier Symbole
		Symbole * popSymbole();

	protected:

		void printEtats();
		void printSymboles();

		// Chaine entree par l'utilisateur
		string chaine;

		// Lexer de la chaine
		Lexer * lexer;
		// Pile des Etats
		vector <Etat *> etats;
		// Pile des Symboles
		vector <Symbole *> symboles;
};
