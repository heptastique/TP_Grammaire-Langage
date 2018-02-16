#include "lexer.h"

// Lecture d'un Symbole de la chaine
Symbole * Lexer::consulter()
{
	// Si le Symbole en cours de lecture n'est pas defini
	// (On doit lire le prochain Symbole de la chaine)
	if (!tampon)
	{
		// Si la position de la tete de lecture est egale a la taille de la chaine
		// (On a lu toute la chaine)
		if (tete == flux.length())
		{
			// Le symbole en cours de lecture est '$' (fin de la chaine)
			tampon = new Symbole(FIN);
		}
		// Sinon (on a pas encore lu toute la chaine)
		else
		{
			// Switch sur le Symbole de la chaine a la position de la tete de lecture
			switch (flux[tete])
			{
				case '(':
					// Le Symbole en cours de lecture est '('
					tampon = new Symbole(OPENPAR);
					// Avancee de la tete de lecture de 1 Symbole
					tete = tete + 1;
					break;
				case ')':
					// Le Symbole en cours de lecture est ')'
					tampon = new Symbole(CLOSEPAR);
					// Avancee de la tete de lecture de 1 Symbole
					tete = tete + 1;
					break;
				case '*':
					// Le Symbole en cours de lecture est '*'
					tampon = new Symbole(MULT);
					// Avancee de la tete de lecture de 1 Symbole
					tete = tete + 1;
					break;
				case '+':
					// Le Symbole en cours de lecture est '+'
					tampon = new Symbole(PLUS);
					// Avancee de la tete de lecture de 1 Symbole
					tete = tete + 1;
					break;
				// Sinon
				default:
				{
					// Si le Symbole en cours de lecture est un chiffre entre '0' et '9'
					if (flux[tete] <= '9' && flux[tete] >= '0')
					{
						// Resultat vaut la valeur du chiffre ((int)'0' = valeur ASCII du caractere '0')
						int resultat = flux[tete] - '0';
						int i = 1;

						// Tant que le Symbole en cours de lecture est un chiffre entre '0' et '9'
						// (On est en train de lire un nombre)
						while (flux[tete+i] <= '9' && flux[tete+i] >= '0')
						{
							// Resultat est multiplie par 10 et on ajoute la valeur du nouveau chiffre lu
							resultat = resultat * 10 + (flux[tete + i] - '0');
							i = i + 1;
						}

						// Avancee de la tete de lecture du nombre de chiffres lus
						tete = tete + i;
						// Le symbole lu est est le nombre evalue
						tampon = new Entier(resultat);
					}
					// Sinon
					else
					{
						// Le symbole lu est le symbole d'erreur
						tampon = new Symbole(ERREUR);
					}
				}
			}
		}
	}

	return tampon;
}

// Avancer la tete de lecture
void Lexer::avancer()
{
	// Le Symbole en cours de lecture n'est pas defini
	tampon = nullptr;
}