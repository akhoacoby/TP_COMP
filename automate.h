#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>
#include <string>
#include <iostream>
#include "symbole.h"
#include "lexer.h"

class Etat; // Déclaration anticipée

class Automate {
  protected:
    std::vector<Symbole *> symbolstack;
    std::vector<Etat *> statestack;
    Lexer *lexer;

  public:
    Automate(std::string chaine);
    ~Automate();
    
    void execution();
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
    
    // Pour l'évaluation finale
    void afficheResultat();
};

#endif