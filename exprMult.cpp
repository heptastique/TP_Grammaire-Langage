#include <iostream>
#include "exprMult.h"

ExprMult::~ExprMult()
{
	delete left;
	delete right;
}

int ExprMult::eval()
{
	#ifdef DEBUG
	cout << "Calcul de la somme.\n";
	#endif
	return left->eval() * right->eval();
}

void ExprMult::Affiche()
{}
