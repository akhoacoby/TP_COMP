#pragma once

#include <string>
using namespace std;

enum Identificateurs
{
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   EXPR,
   INT,
   FIN,
   ERREUR
};

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "EXPR"
                                                                    "INT",
                             "FIN", "ERREUR"};

class Symbole
{
public:
   Symbole(int i) : ident(i) {}
   virtual ~Symbole() {}
   operator int() const { return ident; }
   virtual void Affiche();

protected:
   int ident;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT), valeur(v) {}
   ~Entier() {}
   virtual void Affiche();
   int getValeur() const { return valeur; }

protected:
   int valeur;
};

class Expr : public Symbole
{
public:
   Expr(int v) : Symbole(EXPR), valeur(v) {}
   int getValeur() const { return valeur; }

private:
   int valeur;
};