#include <algorithm>
#include <iostream>
#include "automate.h"
#include "etat.h"

Automate::Automate(std::string chaine) {
    lexer = new Lexer(chaine); //
    statestack.push_back(new E0()); 
    fini = false;
}

Automate::~Automate() {
    while(!statestack.empty()) { delete statestack.back(); statestack.pop_back(); }
    while(!symbolstack.empty()) { delete symbolstack.back(); symbolstack.pop_back(); }
    delete lexer;
}

void Automate::execution() {
    while(!fini) {
        Symbole * s = lexer->Consulter(); //
        // On demande à l'état. S'il renvoie true, cela signifie "Accepter" (fin)
        if (statestack.back()->transition(*this, s)) {
            fini = true;
        }
    }
}

Symbole * Automate::popSymbol() {
    Symbole * s = symbolstack.back();
    symbolstack.pop_back();
    return s;
}

void Automate::popAndDestroySymbol() {
    Symbole * s = symbolstack.back();
    symbolstack.pop_back();
    delete s; // Libère la mémoire du symbole (utile pour les terminaux comme '+')
}

// Pour les Terminaux : On empile et on avance le Lexer
void Automate::decalage(Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer(); //
}

// Pour les Non-Terminaux (EXPR) : On empile seulement
void Automate::transitionsimple(Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    // Ici, pas de lexer->Avancer() !
}

void Automate::reduction(int n, Symbole * s) {
    std::vector<Symbole *> poped;
    
    // 1. On dépile n éléments selon la règle [cite: 6, 7, 8, 9]
    for(int i = 0; i < n; i++) {
        delete statestack.back();
        statestack.pop_back();
        poped.push_back(symbolstack.back());
        symbolstack.pop_back();
    }
    std::reverse(poped.begin(), poped.end());
    
    // 2. Calcul (on utilise l'opérateur int() de symbole.h pour les valeurs)
    int res = 0;
    if (n == 1) { // E -> val [cite: 9]
        res = (int)(*poped[0]); 
    } else if (n == 3) {
        if ((int)(*poped[0]) == OPENPAR) res = (int)(*poped[1]); // E -> (E) [cite: 8]
        else if ((int)(*poped[1]) == PLUS) res = (int)(*poped[0]) + (int)(*poped[2]); // E -> E+E [cite: 6]
        else if ((int)(*poped[1]) == MULT) res = (int)(*poped[0]) * (int)(*poped[2]); // E -> E*E [cite: 7]
    }

    // 3. On crée le nouveau symbole résultat (un Entier qui joue le rôle d'EXPR)
    Symbole * s_res = new Entier(res); 
    
    // 4. On utilise transitionsimple pour le GOTO vers l'état suivant 
    // On demande à l'état qui est maintenant au sommet de la pile
    statestack.back()->transition(*this, s_res);
}