#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include "B+Tree.h"
#include "pair.h"

template <typename K, typename V>
class Map
{
public:
    typedef BPlusTree<Pair<K, V> > map_base;
    class Iterator{
    public:
        friend class Map;
        Iterator(typename map_base::Iterator it = NULL) {
          _it = it;
        }
        Iterator operator ++(int unused) {
          return _it++;
        }
        Iterator operator ++() {
          return ++_it;
        }
        Pair<K, V> operator *() {
          return *_it;
        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) {
          return lhs._it == rhs._it;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs) {
          return lhs._it != rhs._it;
        }

    private:
        typename map_base::Iterator _it;

    };

    Map();

//  Iterators
    Iterator begin() {
      Iterator i(map.begin());
      return i;
    }
    Iterator end() {
      Iterator i(map.end());
      return i;
    }

//  Capacity
    int size() const;
    bool empty() const;

//  Element Access
    V& operator[](const K& key);
    const V& operator[](const K& key) const;
    V& at(const K& key);
    const V& at(const K& key) const;

//  Modifiers
    bool insert(const K& k, const V& v);
    bool erase(const K& key);
    void clear();
    V& get(const K& key);
    const V& get(const K& key) const;

//  Operations:
    Iterator find(const K& key);
    bool contains(const K& key) const;


    bool is_valid(){return map.is_valid();}

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        //outs << print_me.map;
        print_me.map.print_as_list(outs);
        return outs;
    }
private:
    BPlusTree<Pair<K, V> > map;
};

template <typename K, typename V>
Map<K,V>::Map() {
}

template <typename K, typename V>
int Map<K,V>::size() const {
  return map.size();
}

template <typename K, typename V>
bool Map<K,V>::empty() const {
  return map.empty();
}

template <typename K, typename V>
V& Map<K,V>::operator[](const K& key) {
  return get(key);
}

template <typename K, typename V>
const V& Map<K,V>::operator[](const K& key) const{
  return get(key);
}

template <typename K, typename V>
V& Map<K,V>::at(const K& key) {
  return get(key);
}

template <typename K, typename V>
const V& Map<K,V>::at(const K& key) const {
  return get(key);
}

template <typename K, typename V>
bool Map<K,V>::insert(const K& k, const V& v) {
  return map.insert(Pair<K,V>(k,v));
}

template <typename K, typename V>
bool Map<K,V>::erase(const K& key) {
  return map.remove(Pair<K,V>(key));
}

template <typename K, typename V>
void Map<K,V>::clear() {
  map.clear_tree();
}

template <typename K, typename V>
V& Map<K,V>::get(const K& key) {
  return map.get(Pair<K,V>(key)).value;
}

template <typename K, typename V>
const V& Map<K,V>::get(const K& key) const {
  return map.get_existing(Pair<K,V>(key)).value;
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::find(const K& key) {
  return map.find(Pair<K,V>(key));
}

template <typename K, typename V>
bool Map<K,V>::contains(const K& key) const {
  return (map.contains(Pair<K,V>(key)));
}

#endif  // MAP_H_