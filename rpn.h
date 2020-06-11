#ifndef RPN_H_
#define RPN_H_

#include <iostream>
#include <string>

#include "../../Stack and Queue Design/!includes/queue/queue.h"
#include "../../Stack and Queue Design/!includes/stack/stack.h"
#include "../../../Practice/Vector Class/!includes/vector.h"
#include "../../B+Tree/Includes/mmap.h"
#include "../../B+Tree/Includes/map.h"
#include "entity.h"
#include "operator.h"


class RPN {
 public:
  // constructor
  RPN(Map<string, MMap<string, long> >,Queue<string>);
  // evaluates postfix expression and returns vector of indices
  Vector<long> evaluate();

 private:
  // helper functions for evaluate
  Vector<long> get_indices(Vector<string> condition);
  Entity calculate(Entity, string, Entity);
  // variables/structures
  Map<string, MMap<string, long> > _indices;
  Queue<string> _queue;
  Operator op;
  
};

#endif  // RPN_H_

