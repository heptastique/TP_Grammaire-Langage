//
// Created by Vincent on 13/02/2018.
//
#pragma once

#include "symbole.h"
#include <map>

class Expr : public Symbole {
public:
    Expr():Symbole(EXPR) {}
    ~Expr() {}
    virtual double eval(const map<string, double>
                        & valeurs) = 0;
};

