#pragma once

#include <string>
#include "symbole.h"

using namespace std;

class Lexer
{
   public:

      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { }

      Symbole * consulter();
      void avancer();

   protected:

      string flux;
      int tete;
      Symbole * tampon;
};
