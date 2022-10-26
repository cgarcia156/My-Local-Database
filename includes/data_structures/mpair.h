#ifndef M_PAIR_H_
#define M_PAIR_H_

#include "vector.h"
#include "array_utility_functions.h"

template <typename K, typename V>
struct MPair{
    K key;
    Vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
    //--------------------------------------------------------------------------------
    MPair(const K& k=K()) : key(k) {}
    MPair(const K& k, const V& v) {
      key = k;
      value_list+=v;
    }
    MPair(const K& k, const vector<V>& vlist) {
      key = k;
      value_list = vlist;
    }
    //--------------------------------------------------------------------------------

    //You'll need to overload << for your vector:
    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me) {
      outs << "[" << print_me.key << "|" << print_me.value_list << "]";
      return outs;
    }
    
    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
      return (lhs.key == rhs.key);
    }
    friend bool operator!=(const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
    return (lhs.key!=rhs.key);
   }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
      return (lhs.key < rhs.key);
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
      return (lhs.key <= rhs.key);
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
      return (lhs.key > rhs.key);
    }
    MPair<K, V> operator += (const MPair<K, V>& other) {
      assert(key==other.key);
      for(int i=0;i<other.value_list.size();++i) {
        value_list+=other.value_list[i];
      }
      return *this;
    }
};


#endif  // M_PAIR_H_