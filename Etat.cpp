#include <string>
#include "symbole.h"
#include "Etat.h"
using namespace std;

bool E0::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case OPENPAR:
               automate.decalage(automate.E2);
               break;
          case INT:
               automate.decalage(automate.E3);
               break;
          default:
               return false;
     }
     return true;
}

bool E1::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case PLUS:
               automate.decalage(automate.E4);
               break;
          case MULT:
               automate.decalage(automate.E5);
               break;
          default:
               return false;
     }
     return true;
}

bool E2::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case OPENPAR:
               automate.decalage(automate.E2);
               break;
          case INT:
               automate.decalage(automate.E3);
               break;
          default:
               return false;
     }
     return true;
}

bool E3::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case PLUS:
               automate.reduction(1, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() + automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case MULT:
               automate.reduction(1, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case CLOSEPAR:
               automate.reduction(1, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case FIN:
               automate.reduction(1, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          default:
               return false;
     }
     return true;
}

bool E4::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case OPENPAR:
               automate.decalage(automate.E2);
               break;
          case INT:
               automate.decalage(automate.E3);
               break;
          default:
               return false;
     }
     return true;
}


bool E5::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case OPENPAR:
               automate.decalage(automate.E2);
               break;
          case INT:
               automate.decalage(automate.E3);
               break;
          default:
               return false;
     }
     return true;
}


bool E6::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case PLUS:
               automate.decalage(automate.E4);
               break;
          case MULT:
               automate.decalage(automate.E5);
               break;
          case CLOSEPAR:
               automate.decalage(automate.E9);
               break;
          default:
               return false;
     }
     return true;
}


bool E3::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case PLUS:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() + automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case MULT:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case CLOSEPAR:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case FIN:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          default:
               return false;
     }
     return true;
}


bool E3::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case PLUS:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() + automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case MULT:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case CLOSEPAR:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case FIN:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          default:
               return false;
     }
     return true;
}


bool E9::transition(Automate & automate, Symbole * s) {
     switch (s->ident) {
          case PLUS:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() + automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case MULT:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case CLOSEPAR:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          case FIN:
               automate.reduction(3, new Expression(automate.symbolstack[automate.symbolstack.size() - 3]->getValeur() * automate.symbolstack[automate.symbolstack.size() - 1]->getValeur()));
               break;
          default:
               return false;
     }
     return true;
}