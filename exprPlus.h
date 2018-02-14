#pragma once

#include "expr.h"

class ExprPlus : public Expr
{
	public:
		ExprPlus():Expr(EXPR) {}
		~ExprPlus() {}
		double eval(const map<string, double>
                        & valeurs);
};
