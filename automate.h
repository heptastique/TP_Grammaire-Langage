#pragma once
#include "debug.h"
#include <vector>
#include "lexer.h"
#include "expr.h"

using namespace std;

class Etat;
class Automate {
public:
    Automate(string chaine);
    virtual ~Automate();

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
    
    Symbole* popAndDestroySymbol();

protected:
    Lexer * l;
    vector<Etat *> etats;
    vector<Symbole *> symboles;
};

