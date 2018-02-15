//
// Created by Vincent on 12/02/2018.
//

#include <iostream>
#include "etat.h"
#include "automate.h"
#include "e0.h"

Automate::Automate(string chaine) {
    lexer = new Lexer(chaine);
    this->chaine = chaine;
    Etat *etat0 = new E0("E0");
    etats.push_back(etat0);
}

void Automate::lecture() {
    Symbole *s;
    bool fini = false;

    while(!fini) {
        s = lexer->Consulter();
        fini = etats.back()->transition(*this, s);
    }
}

void Automate::decalage(Symbole * s, Etat * e) {
    symboles.push(s);
    etats.push_back(e);
    
    // Seulement si le symbole est terminal
    if((int) *s < 5)
    {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole *s) {
    for(int i = 0; i<n; i++) {
        // On depile le dernier etat
        delete(etats.back());
        etats.pop_back();
    }

    // On reprend la transition
    etats.back()->transition(*this, s);
}

Symbole * Automate::pop()
{
    Symbole * s1 = symboles.top();
    symboles.pop();
    return s1;
}
