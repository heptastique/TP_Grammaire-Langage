//
// Created by Vincent on 12/02/2018.
//

#include <iostream>
#include "automate.h"
#include "e0.h"

Automate::Automate(string chaine)
{
    lexer = new Lexer (chaine);
    this->chaine=chaine;

    Etat *etat0 = new E0("etat0");
    etats.push_back(etat0);
}

void Automate::lecture()
{
    Symbole * s;
    Statut statut = EN_COURS;
    while(statut == EN_COURS)
    {
        s=lexer->Consulter();
        statut = etats.back()->transition(*this, s);
    }

    switch (statut){
        case TERMINE:
            cout << "Le resultat est : ";
            symboles.back()->Affiche();
            break;
        case ERREUR_GRAMMAIRE:
            cout << "Erreur de grammaire" << endl;
            break;
        case ERREUR_SYNTAXE:
            cout << "Erreur de syntaxe" << endl;
            break;
        default:
            cout << "default ne devrait pas arriver" << endl;
            break;
    }

}

void Automate::decalage(Symbole * s, Etat * e)
{
    symboles.push_back(s);
    etats.push_back(e);
    if((int) *s < 5)
    {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole *s)
{
    for(int i =0; i<n; i++)
    {
        delete(etats.back());
        etats.pop_back();
    }
    etats.back()->transition(*this, s);
}

void Automate::back(Symbole *s)
{
    etats.back()->transition(*this,s);
}

Symbole * Automate::pop()
{
    Symbole * s1 = symboles.back();
    symboles.pop_back();
    return s1;
}
