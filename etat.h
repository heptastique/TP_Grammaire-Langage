# pragma once

# include <iostream>

# include "automate.h"

class Etat
{
	public:

		Etat (string name);
		virtual ~Etat();

		void print() const;
		
		// Transition
			// Symbole lu
		virtual bool transition(Automate & automate, Symbole * symbole) = 0;

	protected:

		string name;
};
