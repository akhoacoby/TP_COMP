#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "symbole.h"

int main(void)
{
   string chaine("(1+34)*123");
   // string chaine("(1)");

   Lexer l(chaine);

   Symbole *s;
   while (*(s = l.Consulter()) != FIN)
   {
      s->Affiche();
      cout << endl;
      l.Avancer();
   }

   Automate a(chaine);
   a.execution();

   return 0;
}
