//
// Created by Vincent on 12/02/2018.
//

#include <iostream>
#include "automate.h"

Automate::Automate(string chaine
{
    lexer = new Lexer (chaine);
    this->chaine=chaine;
}

void Automate::lecture()
{

    Symbole * s;
    while(*(s=lexer->Consulter())!=FIN) {
        s->Affiche();
        cout<<endl;
        lexer->Avancer();
    }
}

void Automate::decalage(Symbole * s, Etat * e)
{
    symboles.push_back(s);
    etats.push_back(e);
    lexer->Avancer();
}

void Automate::reduction(int n, Symbole *s)
{
    for(int i =0; i<n; i++)
    {
        delete(etats.pop_back());
        etats.pop_back();
    }
}
