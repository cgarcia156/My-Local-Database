#ifndef M_MAP_H_
#define M_MAP_H_

#include <iostream>
#include "B+Tree.h"
#include "mpair.h"
#include "vector.h"

template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it = NULL) {
          _it = it;
        }
        Iterator operator ++(int unused) {
          return _it++;
        }
        Iterator operator ++() {
          return ++_it;
        }
        MPair<K, V> operator *() {
          return *_it;
        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) {
          return lhs._it == rhs._it;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs) {
          return lhs._it != rhs._it;
        }
        bool is_null() {
          return (_it==NULL);
        }

    private:
        typename map_base::Iterator _it;
    };

    MMap();

//  Iterators
    Iterator begin() {
      Iterator i(mmap.begin());
      return i;
    }
    Iterator end() {
      Iterator i(mmap.end());
      return i;
    }

//  Capacity
    int size() const;
    bool empty() const;

//  Element Access
    const Vector<V>& operator[](const K& key) const;
    Vector<V>& operator[](const K& key);

//  Modifiers
    void insert(const K& k, const V& v);
    bool erase(const K& key);
    void clear();

//  Operations:
    bool contains(const K& key) const ;
    Vector<V> &get(const K& key);
    const Vector<V> &get(const K& key) const;

    Iterator find(const K& key);
    int count(const K& key) const;
    Iterator lower_bound(const K& key);
    Iterator upper_bound(const K& key);

    bool is_valid() {return mmap.is_valid();}

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        //outs << print_me.mmap;
        print_me.mmap.print_as_list(outs);
        return outs;
    }

private:
  BPlusTree<MPair<K,V> >mmap;
};

template <typename K, typename V>
MMap<K,V>::MMap() {
}

template <typename K, typename V>
int MMap<K,V>::size() const {
  return mmap.size();
}

template <typename K, typename V>
bool MMap<K,V>::empty() const {
  return mmap.empty();
}

template <typename K, typename V>
const Vector<V>& MMap<K,V>::operator[](const K& key) const {
  return get(key);
}

template <typename K, typename V>
Vector<V>& MMap<K,V>::operator[](const K& key) {
  return get(key);
}

template <typename K, typename V>
void MMap<K,V>::insert(const K& k, const V& v) {
  mmap.insert(MPair<K,V>(k,v));
}

template <typename K, typename V>
bool MMap<K,V>::erase(const K& key) {
  return mmap.remove(MPair<K,V>(key));
}

template <typename K, typename V>
void MMap<K,V>::clear() {
  mmap.clear_tree();
}

template <typename K, typename V>
bool MMap<K,V>::contains(const K& key) const {
  return (mmap.contains(MPair<K,V>(key)));
}

template <typename K, typename V>
Vector<V>& MMap<K,V>::get(const K& key) {
  return mmap.get(MPair<K,V>(key)).value_list;
}

template <typename K, typename V>
const Vector<V>& MMap<K,V>::get(const K& key) const {
  assert(contains(key));
  return mmap.get_existing(MPair<K,V>(key)).value_list;
}

template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::find(const K& key) {
  return mmap.find(MPair<K,V>(key));
}

template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::lower_bound(const K& key) {
  return mmap.lower_bound(key);
}

template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::upper_bound(const K& key) {
  Iterator it = mmap.upper_bound(key);
  if (!it.is_null()) {
  return mmap.upper_bound(key);
  }
  return end();
}

template <typename K, typename V>
int MMap<K,V>::count(const K& key) const {
  return get(key).size();
}

#endif  // M_MAP_H_