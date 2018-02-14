//
// Created by Vincent on 13/02/2018.
//

#include "e3.h"

E3::E3(string name) : Etat(name) {}

E3::~E3() {}

bool E3::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case PLUS:
			automate.reduction(1, s);
			break;
		case MULT:
			automate.reduction(1, s);
			break;
		case CLOSEPAR:
			automate.reduction(1, s);
			break;
		case FIN:
			automate.reduction(1, s);
			break;
	
	}
	return false;
}
