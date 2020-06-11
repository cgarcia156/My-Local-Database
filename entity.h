#ifndef ENTITY_H_
#define ENTITY_H_

#include "../../../Practice/Vector Class/!includes/vector.h"

class Entity {
 public:
  Entity(string s) : sym(s) { type = "String"; }
  Entity(Vector<long> v) : nums(v) { type = "Vector"; }
  string get_type() { return type; }
  string get_sym() { return sym; }
  Vector<long> get_nums() { return nums; }

 private:
  string sym;
  string type;
  Vector<long> nums;
};

#endif  // ENTITY_H_
