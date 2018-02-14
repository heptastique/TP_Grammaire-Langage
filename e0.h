# pragma once

# include "etat.h"

class E0 : public Etat
{
	public:

		E0(string name);
		~E0();

		void print() const;
		bool transition(Automate & automate, Symbole * symbole);
};
