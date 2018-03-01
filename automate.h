#pragma once

#include <stack>
#include <vector>
#include "lexer.h"

using namespace std;

class Etat;
class Automate {
public:
    Automate(string chaine);
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

    Symbole * pop();

    void reduction(int n,Symbole * s);
    void printEtats();
    void printSymboles();

protected:
    string chaine;

    Lexer * lexer;

    vector<Etat *> etats;
    vector<Symbole *> symboles;
};

