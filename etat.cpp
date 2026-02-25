#include "etat.h"

bool E0::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.transitionSimple(s, new E1);
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E1::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case FIN:
        return true;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E2::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E6);
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E3::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        Entier *e = (Entier *)automate.popSymbol();
        int v = e->getValeur();
        automate.reduction(1, new Expr(v));

        break;

    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E4::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E7);
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E5::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E8);
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E6::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new E9);
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E7::transition(Automate &automate, Symbole *s)
{
    int reductionR2 = 3; // je sais pas c'est combien ici, ca dépend je pense
    switch (*s)
    {
    case MULT:
        automate.decalage(s, new E5);
        break;
    case PLUS:
    case CLOSEPAR:
    case FIN:
        Expr *s1 = (Expr *)automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr *s2 = (Expr *)automate.popSymbol();
        int v = s1->getValeur() + s2->getValeur();
        automate.reduction(3, new Expr(v));
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E8::transition(Automate &automate, Symbole *s)
{
    int reductionR3 = 3; // je sais pas c'est combien ici, ca dépend je pense
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        Expr *s1 = (Expr *)automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr *s2 = (Expr *)automate.popSymbol();
        int v = s1->getValeur() * s2->getValeur();
        automate.reduction(3, new Expr(v));
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E9::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        automate.popAndDestroySymbol();
        Expr *e = (Expr *)automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3, e);
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}