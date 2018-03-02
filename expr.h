#pragma once
#include "debug.h"
#include "symbole.h"
#include <map>

class Expr : public Symbole {
public:
    Expr():Symbole(EXPR) {}
    ~Expr() {}
protected:
	int valeur;
};

