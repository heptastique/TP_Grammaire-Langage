//
// Created by Vincent on 12/02/2018.
//

#include <iostream>
#include "automate.h"
#include "lexer.h"

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
