#include "rpn.h"
#include "operator.h"

// constructor
RPN::RPN(Map<string, MMap<string, long> > i, Queue<string> q)
    : _indices(i), _queue(q) {
}

// evaluates postfix expression and returns vector of indices
Vector<long> RPN::evaluate() {
  Stack<Entity> s;

  while (!_queue.empty()) {
    // push non-operators into the stack
    if (!op.types.contains(_queue.front())) {
      s.push(Entity(_queue.pop()));
    } else {
      // pop twice and calculate the indices
      Entity e2 = s.pop();
      Entity e1 = s.pop();
      Entity e3 = calculate(e1, _queue.pop(), e2);
      s.push(e3);
    }
  }
  Entity e4 = s.pop();
  Vector<long> result = e4.get_nums();
  return result;
}

Entity RPN::calculate(Entity e1, string s, Entity e2) {
  bool DEBUG = false;
  // for <,>,<=,>=,= operations
  if (op.types[s] == op.OPERATOR1) {
    Vector<string> v({e1.get_sym(), s, e2.get_sym()});
    Vector<long> indices = get_indices(v);

    if (DEBUG) {
      cout << indices << endl;
    }

    return Entity(indices);

  } // find intersection of vectors for AND
  else if (op.types[s] == op.OPERATOR2) {
    return Entity(v_inter(e1.get_nums(), e2.get_nums()));

  } // find union of vectors for OR
  else {
    return Entity(v_union(e1.get_nums(), e2.get_nums()));
  }
}

Vector<long> RPN::get_indices(Vector<string> condition) {
  Vector<long> indices;

  if (op.sym[condition[1]] == op.EQUAL) {
    Vector<long> result = _indices[condition[0]][condition[2]];
    // add result to indices
    indices += result;

  } else if (op.sym[condition[1]] == op.LE) {
    MMap<string, long>::Iterator it = _indices[condition[0]].begin();
    while (it != _indices[condition[0]].upper_bound(condition[2])) {
      // add this to indices
      indices += ((*it).value_list);
      it++;
    }
  } else if (op.sym[condition[1]] == op.GE) {
    MMap<string, long>::Iterator it =
        _indices[condition[0]].lower_bound(condition[2]);
    while (it != _indices[condition[0]].end()) {
      // add this to indices
      indices += ((*it).value_list);
      it++;
    }
  } else if (op.sym[condition[1]] == op.LTHAN) {
    MMap<string, long>::Iterator it = _indices[condition[0]].begin();
    while (it != _indices[condition[0]].lower_bound(condition[2])) {
      // add this to indices
      //indices = v_union(indices, (*it).value_list);
      indices += ((*it).value_list);
      it++;
    }
  } else if (op.sym[condition[1]] == op.GTHAN) {
    MMap<string, long>::Iterator it =
        _indices[condition[0]].upper_bound(condition[2]);
    while (it != _indices[condition[0]].end()) {
      // add this to indices
      indices += ((*it).value_list);
      it++;
    }
  }

  return indices;
}