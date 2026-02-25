#include <algorithm>
#include "automate.h"
#include "etat.h" // Assure-toi d'avoir ce fichier avec tes classes E0, E1...

Automate::Automate(std::string chaine) {
    lexer = new Lexer(chaine); [cite: 16]
    // L'état initial est l'état 0
    statestack.push_back(new E0()); 
}

Automate::~Automate() {
    while(!statestack.empty()) {
        delete statestack.back();
        statestack.pop_back();
    }
    while(!symbolstack.empty()) {
        delete symbolstack.back();
        symbolstack.pop_back();
    }
    delete lexer;
}

void Automate::execution() {
    bool fini = false;
    while(!fini) {
        // On consulte le prochain symbole sans avancer la tête de lecture
        Symbole * s = lexer->Consulter(); [cite: 15]
        
        // On délègue la décision à l'état au sommet de la pile
        // La transition retourne 'true' si on doit continuer, 'false' si on accepte
        if (statestack.back()->transition(*this, s)) {
            fini = false; 
        } else {
            fini = true; // Cas "Accepter" de la table
        }
    }
    std::cout << "Analyse terminée avec succès." << std::endl;
}

void Automate::decalage(Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer(); // On avance réellement la tête de lecture 
}

void Automate::reduction(int n, Symbole * s) {
    std::vector<Symbole *> poped;
    
    // On dépile n états et n symboles
    for(int i = 0; i < n; i++) {
        delete statestack.back();
        statestack.pop_back();
        poped.push_back(symbolstack.back());
        symbolstack.pop_back();
    }
    
    // On remet les symboles dans l'ordre de lecture (gauche à droite)
    std::reverse(poped.begin(), poped.end());
    
    // Logique d'évaluation (E -> val ou E -> E+E)
    // Ici, on crée un nouvel objet "Entier" ou "Expr" avec le résultat du calcul
    Symbole * resultat;
    if (n == 1) { 
        // Cas E -> val [cite: 9]
        resultat = poped[0]; 
    } else if (n == 3) {
        // Cas E -> E+E, E*E ou (E) [cite: 6, 7, 8]
        // À implémenter selon ton schéma : new ExprPlus(poped[0], poped[2]), etc.
        resultat = new Entier(0); // Placeholder
    }

    // GOTO : On regarde l'état au sommet et on applique la transition pour le non-terminal E
    statestack.back()->transition(*this, resultat);
}