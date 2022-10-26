#ifndef SHUNTING_YARD_H_
#define SHUNTING_YARD_H_

#include <iostream>

#include "data_structures/queue.h"
#include "data_structures/stack.h"
#include "data_structures/map.h"
#include "data_structures/vector.h"
#include "operator.h"


class SY {
 public:
  SY(Vector<string> conditions);
  Queue<string> get_postfix() {return postfix;}
  bool fail() {return _fail;}
 private:
  Vector<string> infix;
  Queue<string> postfix;
  Operator op;
  bool _fail;
  int prec(string s);
  void evaluate(Vector<string> v);
};


#endif  // SHUNTING_YARD_H_
