class Symbol() {
     protected:
          int ident;
     public:
          Symbol(int ident) {
               this->ident = ident;
          }
          virtual ~Symbol() {}
          void print();
          operator int() const {
               return ident;
          }
};