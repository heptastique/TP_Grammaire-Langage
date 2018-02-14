#include <iostream>
#include "lexer.h"

int main(void)
{
   string chaine( "(1+34)*123" );

   Lexer lexer(chaine);

   Symbole * s;

   while ( *(s = lexer.Consulter()) != FIN)
   {
      s -> Affiche();
      cout << endl;
      lexer.Avancer();
   }

   return 0;
}

