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
    bool fini;

  public:
    Automate(std::string chaine);
    ~Automate();
    
    void execution();
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
    void transitionsimple(Symbole * s, Etat * e);
    Symbole * popSymbol();            // Récupère le sommet de pile et le retire
    void popAndDestroySymbol();
    
    // Pour l'évaluation finale
    void afficheResultat();
};

#endif