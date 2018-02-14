//
// Created by Vincent on 12/02/2018.
//

#include <iostream>
#include "automate.h"

void Automate::lecture() {
    cout << "Entrez votre chaine :" << endl;
    cin >> chaine;

    Lexer l(chaine);

    Symbole * s;
    while(*(s=l.Consulter())!=FIN) {
        s->Affiche();
        cout<<endl;
        l.Avancer();
    }
}

void Automate::decalage(Symbole * s, Etat * e) {
    symboles.push(s);
    etats.push(e);
    /*if(int(s)!=5)
    {
		//l.Avancer();
	}*/
}

void Automate::reduction(int n,Symbole * s) {
	for(int i=0; i<n; i++)
	{
		etats.pop();
	}
	//etats.top()->transition(*this, s);
}
