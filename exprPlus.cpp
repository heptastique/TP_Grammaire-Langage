#include <iostream>
#include "exprPlus.h"

ExprPlus::~ExprPlus()
{
	delete left;
	delete right;
}

int ExprPlus::eval()
{ 
	#ifdef DEBUG
	cout << "Calcul de la somme.\n";
	#endif
	return left->eval()+right->eval(); 
}

void ExprPlus::Affiche()
{}
