#pragma once

#include <stack>
#include "lexer.h"
#include "expr.h"

using namespace std;

class Etat;
class Automate {
public:
    Automate(string chaine) : l(chaine) {}
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
    
    void putSymbol(Symbole * s);
    
    Symbole* popSymbol();
    
    void popAndDestroySymbol();

protected:
    Lexer l;
	
    stack<Etat *> etats;
    stack<Symbole *> symboles;
};

