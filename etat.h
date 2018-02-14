//
// Created by Vincent on 13/02/2018.
//
#pragma  once

#include "symbole.h"
#include "automate.h"

enum Statut { TERMINE, EN_COURS, ERREUR_SYNTAXE, ERREUR_GRAMMAIRE };

class Etat {
public:
    Etat(string name);
    virtual ~Etat();
    void print() const;
    void printTransition(string symbole, string from, string to) const;
    void printReduction(Symbole &s, string from, string message);
    virtual enum Statut transition(Automate & automate, Symbole * s) = 0;
protected:
    string name;
};


