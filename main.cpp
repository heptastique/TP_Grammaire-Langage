#include <iostream>
#include "automate.h"


int main(void) {
   string chaine;

   cout << "Entrez votre chaine :" << endl;
   cin >> chaine;

   Automate automate(chaine);
   automate.lecture();

   return 0;
}

