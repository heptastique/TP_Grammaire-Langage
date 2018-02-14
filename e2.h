# pragma once

# include "etat.h"

class E2 : public Etat
{
	public:

		E2(string name);
		~E2();

		void print() const;
		bool transition(Automate & automate, Symbole * symbole);
};
