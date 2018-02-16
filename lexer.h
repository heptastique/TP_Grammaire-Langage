#pragma once

#include <string>
#include "symbole.h"

using namespace std;

class Lexer
{
	public:

		Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
		~Lexer() { }

		// Lecture d'un Symbole de la chaine
		Symbole * consulter();
		// Avancement de la tete de lecture
		void avancer();

	protected:

		// Chaine a lire
		string flux;
		// Position de la tete de lecture dans la chaine
		int tete;
		// Symbole en cours de lecture
		Symbole * tampon;
};
