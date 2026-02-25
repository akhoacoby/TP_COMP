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
        // automate.transitionSimple(s, new E1);
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
        // automate.accepter();
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
        automate.reduction(1, s); // C'est pas vraiment ca
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
        automate.reduction(reductionR2, s); // C'est pas vraiment ca
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
        automate.reduction(reductionR3, s); // C'est pas vraiment ca
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}

bool E9::transition(Automate &automate, Symbole *s)
{
    int reductionR4 = 3; // je sais pas c'est combien ici, ca dépend je pense
    switch (*s)
    {
    case PLUS:
        automate.reduction(reductionR4, s);
        break;
    case MULT:
    case CLOSEPAR:
    case FIN:
        automate.reduction(reductionR4, s); // C'est pas vraiment ca
        break;
    default:
        cout << "Erreur de syntaxe" << endl;
        break;
    }
    return false;
}