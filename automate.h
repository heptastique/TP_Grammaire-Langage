#pragma once

#include <stack>
#include <vector>
#include "lexer.h"

using namespace std;

class Etat;
class Automate {
public:
    Automate(){  }
    virtual ~Automate() { }

    /**
     * Lis la chaine de caractère donné par l'utilisateur.
     */
    void lecture();

    /**
     * Empile un symbole et un etat.
     * @param s
     * @param e
     */
    void decalage(Symbole * s, Etat * e);


    void reduction(int n,Symbole * s);

protected:
    string chaine;

    vector<Etat *> etats;
    stack<Symbole *> symboles;
};

