#pragma once
#include "debug.h"
#include "expr.h"
#include "symbole.h"
#include <map>

class ExprPlus : public Expr {
public:
	ExprPlus(Entier *s1, Entier *s2) : left(s1), right(s2) {}
    ~ExprPlus();

    int eval();
    void Affiche();

protected:
    Entier* left;
    Entier* right;
};
