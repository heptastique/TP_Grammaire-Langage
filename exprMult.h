#pragma once
//#include "debug.h"
#include "expr.h"
#include "symbole.h"
#include <map>

class ExprMult : public Expr {
public:
	ExprMult(Entier *s1, Entier *s2) : left(s1), right(s2) {}
	~ExprMult();

	int eval();
	void Affiche();

protected:
	Entier* left;
	Entier* right;
};
