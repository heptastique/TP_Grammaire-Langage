//
// Created by Vincent on 13/02/2018.
//

#include "etat.h"

Etat::Etat(string name)
{
	this->name = name;
}

bool Etat::transition(Automate & automate, Symbole * s)
{}

Etat::~Etat() {}

/*bool E0::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case INT:
			automate.decalage(s, new E3("E3"));
			break;
		case OPENPAR:
			automate.decalage(s, new E2("E2"));
			break;
	}
	return false;
}

bool E2::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case INT:
			automate.decalage(s, new E3("E5"));
			break;
		case OPENPAR:
			automate.decalage(s, new E2("E2"));
			break;
	}
	return false;
}

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

bool E4::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case INT:
			automate.decalage(s, new E3("E3"));
			break;
		case OPENPAR:
			automate.decalage(s, new E2("E2"));
			break;
	}
	return false;
}

bool E5::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case INT:
			automate.decalage(s, new E3("E3"));
			break;
		case OPENPAR:
			automate.decalage(s, new E2("E2"));
			break;
	}
	return false;
}

bool E6::transition(Automate & automate, Symbole * s)
{
	switch(*s) {
		case PLUS:
			automate.decalage(s, new E4("E4"));
			break;
		case MULT:
			automate.decalage(s, new E5("E5"));
			break;
		case CLOSEPAR:
			automate.decalage(s, new E9("E9"));
			break;
	}
	return false;
}

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

bool E9::transition(Automate & automate, Symbole * s)
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
*/
