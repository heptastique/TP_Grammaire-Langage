//
// Created by Vincent on 13/02/2018.
//
#pragma once

#include "symbole.h"
#include <map>

class Expr : public Entier {
public:
    Expr():Entier(EXPR) {}
    virtual ~Expr() {}
};

