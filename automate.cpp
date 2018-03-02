#include <iostream>
#include "automate.h"
#include "etat.h"
#include "e0.h"
#include "expr.h"
#include "exprPlus.h"

using namespace std;

Automate::Automate(string chaine)
{
	// Création du lexer
	l = new Lexer(chaine);
	// Création et ajout de l'état initial
	Etat *etatInitial = new E0("E0");
	etats.push_back(etatInitial);
}

Automate::~Automate()
{
	delete l;
}

void Automate::lecture()
{
	#ifdef DEBUG
	cout << "Lecture commencée.\n";
	#endif
    Symbole * s;

	// Flag pour l'acceptation (0 : analyse en cours, 1 : analyse terminée, 2 : erreur)
    int end = 0;
  
    while(end==0)
    {
		// Caractère suivant
		s=l->Consulter();
        end = etats.back()->transition(*this, s);
    }

	// Affichage du résultat final.
	if (end == 1)
	{
		cout << "Lecture terminée.\n";
		cout << "Le résultat de la chaîne est : ";
		cout << popSymbol()->eval() << ".";
		cout << endl;
	}
	else if (end == 2)
	{
		cout << "Erreur lexer.";
		cout << endl;
	}
	else
	{
		cout << "Erreur automate.";
		cout << endl;
	}
}

void Automate::decalage(Symbole * s, Etat * e) {
	#ifdef DEBUG
	cout << "Décalage.\n";
	#endif
	// On ajoute le symbole et l'état
    putSymbol(s);
    etats.push_back(e);
	// S'il s'agit d'un terminal, on lit un nouveau caractère, sinon non
    if((int) *s < 5)
    {
        l->Avancer();
    }
}

void Automate::reduction(int n, Symbole * s) {
	#ifdef DEBUG
	cout << "Réduction de " << n << " états.\n";
	#endif
	// On supprime n états de la pile des états
	for(int i=0; i<n; i++)
	{
		delete(etats.back());
		etats.pop_back();
	}
	etats.back()->transition(*this, s);
}

void Automate::putSymbol(Symbole * s)
{
	// On ajoute le symbole au vecteur
	#ifdef DEBUG
	cout << "Symbole " << *s << " is pushed.\n";
	#endif
	symboles.push_back(s);
}

Symbole* Automate::popSymbol()
{
	// On retourne le symbole mais on ne le supprime pas du vecteur
	Symbole * s = symboles.back();
	#ifdef DEBUG
	cout << "Symbole " << *s << " is popped.\n";
	#endif
	return s;
}

Symbole* Automate::popAndDestroySymbol()
{
	// On retourne le symbole et on le supprime du vecteur
	Symbole * s = symboles.back();
	symboles.pop_back();
	#ifdef DEBUG
	cout << "Symbole " << *s << " is popped and destroyed.\n";
	#endif
	return s;
}
