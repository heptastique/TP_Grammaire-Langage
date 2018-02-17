#pragma once

#include <string>

using namespace std;

enum identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole
{
	public:

		Symbole(int id);
		virtual ~Symbole();

		operator int() const;
		virtual void print();

		void setId(int id);

	protected:

		int id;
};

class Entier : public Symbole
{
	public:

		Entier(int v) : Symbole(INT), valeur(v) { }
		~Entier() { }

		virtual void print();

		int getValeur();
		void setValeur(int valeur);

	protected:

		int valeur;
};

