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
        //printf("ON AVANCE\n");
        printEtats();
        printSymboles();
        s = lexer->Consulter();
        fini = etats.back()->transition(*this, s);
    }

    cout << " = " << ((Entier *)symboles.back())->getVal() << endl;
}

void Automate::decalage(Symbole * s, Etat * e) {
    cout << "Decalage vers " << e->getName() << endl;
    symboles.push_back(s);
    etats.push_back(e);
    
    // Seulement si le symbole est terminal
    if((int) *s < 5)
    {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole *s) {
    cout << "Reduction de " << n << " fois avec " << *s << endl;
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
    Symbole * s1 = symboles.back();
    symboles.pop_back();
    return s1;
}

// Affiche la pile des Etats
void Automate::printEtats()
{
	cout << "Etats : {";

	for (int i = 0; i < etats.size(); i = i + 1)
	{
		etats[i]->print();
		cout << ", ";
	}

	cout << "}" << endl;
}

// Affiche la pile des Symboles
void Automate::printSymboles()
{
	cout << "Symboles : {";

	for (int i = 0; i < symboles.size(); i = i + 1)
	{
		symboles[i]->Affiche();
		cout << ", ";
	}

	cout << "}" << endl;
}
