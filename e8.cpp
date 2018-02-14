//
// Created by Vincent on 13/02/2018.
//

#include "e8.h"
#include "e5.h"

E8::E8(string name) : Etat(name) {}

E8::~E8() {}

bool E8::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case PLUS:
			automate.reduction(3, s);
			break;
		case MULT:
			automate.reduction(3, s);
			break;
		case CLOSEPAR:
			automate.reduction(3, s);
			break;
		case FIN:
			automate.decalage(s, new E5("E5"));
			break;
	}
	return false;
}
