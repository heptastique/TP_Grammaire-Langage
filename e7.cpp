//
// Created by Vincent on 13/02/2018.
//

#include "e7.h"
#include "e5.h"

E7::E7(string name) : Etat(name) {}

E7::~E7() {}

bool E7::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case PLUS:
			automate.reduction(3, s);
			break;
		case CLOSEPAR:
			automate.reduction(3, s);
			break;
		case FIN:
			automate.reduction(3, s);
			break;
		case MULT:
			automate.decalage(s, new E5("E5"));
			break;
	}
	return false;
}
