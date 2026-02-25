class Expr : public Symbol {
     public:
          Expr(int ident) : Symbol(EXPR) {}
          virtual ~Expr() {}
          virtual double eval(const map<string, double>& variables) = 0;
          void print();
};