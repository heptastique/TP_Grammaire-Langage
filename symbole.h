#pragma once
#include "debug.h"
#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, EXPR, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }

      operator int() const { return ident; }
      virtual void Affiche();
	  virtual int eval();
      int getIdent();
      void setIdent(int ident);

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int eval() {return valeur;}
	  void setValeur(int valeur) { this->valeur = valeur; }
   protected:
      int valeur;
};
