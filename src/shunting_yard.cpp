#include "../includes/shunting_yard.h"
#include "../includes/operator.h"

// constructor
SY::SY(Vector<string> conditions) {
  // check for parenthesis error
  try{
  evaluate(conditions);
  } catch(const char* e) {
    cout << "\nERROR: " << e << endl << endl;
    _fail = true;
  }
}

void SY::evaluate(Vector<string> v) {
  Stack<string> S;
  Queue<string> Q;
  int p1 = 0;
  int p2 = 0;
  // move through the list while shunting elements
  for (int i = 0; i < v.size(); i++) {
    // push words into the queue
    if (!op.types.contains(v[i])) {
      Q.push(v[i]);
    }  // push ( into stack
    else if (op.types[v[i]] == op.LBRACKET) {
      S.push(v[i]);
    } // if )
    else if (op.types[v[i]] == op.RBRACKET) {
      // pop from stack until ( is found
      if(S.empty()) {
        throw "Left Parenthesis Is Missing!";
      }
      while (op.types[S.top()] != op.LBRACKET) {
        Q.push(S.pop());
        if(S.empty()) {
          throw "Left Parenthesis Is Missing!";
        }
      }
      S.pop();
    } // do this for operators
    else {
      if (!S.empty()) {
        // check precedence
        p1 = prec(v[i]);
        p2 = prec(S.top());
        // move to queue while stack precedence is greater
        while (p2 > p1 && (!S.empty())) {
          Q.push(S.pop());
          if (!S.empty()) {
            p2 = prec(S.top());
          } else {
            p2 = 0;
          }
        }
      } // finally push the operator
      S.push(v[i]);
    }
  }
  // push remaining operators into the queue
  while (!S.empty()) {
    if(op.types[S.top()]==op.LBRACKET) {
      throw "Right Parenthesis Is Missing!";
    }
    Q.push(S.pop());
  }
  // we now have our postfix
  postfix = Q;
}

int SY::prec(string s) {
  Operator op;
  // checks for <,>,=,<=,>=
  if (op.types[s]==op.OPERATOR1) {
    return 3;
    // check for AND
  } else if (op.types[s]==op.OPERATOR2) {
    return 2;
    // checks for OR
  } else if (op.types[s]==op.OPERATOR3) {
    return 1;
  } else {
    return 0;
  }
}