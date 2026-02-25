#include <algorithm>
#include <iostream>
#include "automate.h"
#include "etat.h"

Automate::Automate(std::string chaine)
{
    lexer = new Lexer(chaine); //
    statestack.push_back(new E0());
    fini = false;
}

Automate::~Automate()
{
    while (!statestack.empty())
    {
        delete statestack.back();
        statestack.pop_back();
    }
    while (!symbolstack.empty())
    {
        delete symbolstack.back();
        symbolstack.pop_back();
    }
    delete lexer;
}

void Automate::execution()
{
    while (!fini)
    {
        Symbole *s = lexer->Consulter(); //
        // On demande à l'état. S'il renvoie true, cela signifie "Accepter" (fin)
        if (statestack.back()->transition(*this, s))
        {
            Expr *e = (Expr *)symbolstack.back();
            std::cout << "Résultat = " << e->getValeur() << std::endl;
            fini = true;
        }
    }
}

Symbole *Automate::popSymbol()
{
    Symbole *s = symbolstack.back();
    symbolstack.pop_back();
    return s;
}

void Automate::popAndDestroySymbol()
{
    Symbole *s = symbolstack.back();
    symbolstack.pop_back();
    delete s; // Libère la mémoire du symbole (utile pour les terminaux comme '+')
}

// Pour les Terminaux : On empile et on avance le Lexer
void Automate::decalage(Symbole *s, Etat *e)
{
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer(); //
}

// Pour les Non-Terminaux (EXPR) : On empile seulement
void Automate::transitionsimple(Symbole *s, Etat *e)
{
    symbolstack.push_back(s);
    statestack.push_back(e);
    // Ici, pas de lexer->Avancer() !
}

void Automate::reduction(int n, Symbole *s)
{
    for (int i = 0; i < n; i++)
    {
        delete (statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this, s);
}
