# pragma once

# include "etat.h"

class E7 : public Etat
{
	public:

		E7(string name);
		~E7();

		void print() const;
		bool transition(Automate & automate, Symbole * symbole);
};
