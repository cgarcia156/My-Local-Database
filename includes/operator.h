#ifndef OPERATOR_H_
#define OPERATOR_H_

#include "data_structures/map.h"

class Operator {
 public:
  Operator() { build_types_map(); build_sym_map(); }
  Map<string, int> types;
  Map<string, int> sym;
  enum Type { LBRACKET, RBRACKET, OPERATOR1, OPERATOR2, OPERATOR3 };
  enum Sym {LTHAN,GTHAN,EQUAL,GE,LE};

 private:
  void build_types_map() {
    types["("] = LBRACKET;
    types[")"] = RBRACKET;
    types["<"] = OPERATOR1;
    types["<="] = OPERATOR1;
    types[">"] = OPERATOR1;
    types["="] = OPERATOR1;
    types[">="] = OPERATOR1;
    types["=="] = OPERATOR1;
    types["and"] = OPERATOR2;
    types["And"] = OPERATOR2;
    types["AND"] = OPERATOR2;
    types["&&"] = OPERATOR2;
    types["&"] = OPERATOR2;
    types["or"] = OPERATOR3;
    types["OR"] = OPERATOR3;
    types["Or"] = OPERATOR3;
    types["||"] = OPERATOR3;
  }
  void build_sym_map() {
    sym["<"] = LTHAN;
    sym["<="] = LE;
    sym[">"] = GTHAN;
    sym["="] = EQUAL;
    sym[">="] = GE;
    sym["=="] = EQUAL;
  }
};

#endif  // OPERATOR_H_
