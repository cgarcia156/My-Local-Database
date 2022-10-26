#ifndef PAIR_H_
#define PAIR_H_

#include <iostream>
using namespace std;

template <typename K, typename V>
struct Pair {
  K key;
  V value;

  Pair(const K& k = K(), const V& v = V()) : key(k), value(v) {}
  friend ostream& operator<<(ostream& outs, const Pair<K, V>& print_me) {
    outs << "[" << print_me.key << "|" << print_me.value << "]";
    return outs;
  }
  friend bool operator==(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
    return (lhs.key==rhs.key);
  }
  friend bool operator!=(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
    return (lhs.key!=rhs.key);
  }
  friend bool operator<(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
    return (lhs.key<rhs.key);
  }
  friend bool operator>(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
    return (lhs.key > rhs.key);
  }
  friend bool operator<=(const Pair<K, V>& lhs, const Pair<K, V>& rhs) {
    return (lhs.key<=rhs.key);
  }
  Pair<K,V>& operator=(const Pair<K,V>& RHS) {
    key = RHS.key;
    value = RHS.value;
    return *this;
  }
  Pair<K, V> operator+=(const Pair<K, V>& other) {
    assert(key==other.key);
    value = other.value;
    return *this;
  }
};

#endif  // PAIR_H_