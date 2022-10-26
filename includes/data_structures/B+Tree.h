#ifndef B_PLUS_TREE_H_
#define B_PLUS_TREE_H_

#include <iomanip>
#include <iostream>

#include "array_utility_functions.h"

using namespace cg;

template <class T>
class BPlusTree {
 public:
  class Iterator {
   public:
    friend class BPlusTree;
    Iterator(BPlusTree<T>* _it = NULL, int _key_ptr = 0)
        : it(_it), key_ptr(_key_ptr) {}

    T operator*() {
      assert(key_ptr < it->data_count);
      return it->data[key_ptr];
    }

    Iterator operator++(int un_used) {
      Iterator hold;
      hold.it = it;
      hold.key_ptr = key_ptr++;
      if (key_ptr == it->data_count) {
        it = it->next;
        key_ptr = 0;
      }
      return hold;
    }

    Iterator operator++() {
      key_ptr++;
      if (key_ptr == it->data_count) {
        it = it->next;
        key_ptr = 0;
      }
      return *this;
    }

    friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
      if (lhs.it == rhs.it) {
        if (lhs.it) {
          return (lhs.it->data[lhs.key_ptr] == rhs.it->data[rhs.key_ptr]);
        }
        return true;
      } else {
        return false;
      }
    }

    friend bool operator!=(const Iterator& lhs,const Iterator& rhs) {
      if (lhs.it == rhs.it) {
        if (lhs.it) {
          return (lhs.it->data[lhs.key_ptr]!=rhs.it->data[rhs.key_ptr]);
        }
        return false;
      }
      return true;
    }

    void print_Iterator() {
      assert(!is_null());
      assert(key_ptr < it->data_count);
      cout << it->data[key_ptr];
    }

    bool is_null() { return !it; }

   private:
    BPlusTree<T>* it;
    int key_ptr;
  };

  BPlusTree(bool ignore = false);
  // big three:
  BPlusTree(const BPlusTree<T>& other);
  ~BPlusTree();
  BPlusTree<T>& operator=(const BPlusTree<T>& RHS);

  bool insert(const T& entry);  // insert entry into the tree
  bool remove(const T& entry);  // remove entry from the tree

  void clear_tree();  // clear this object (delete all nodes etc.)
  void copy(const BPlusTree<T>& other);  // copy other into this object
  bool contains(
      const T& entry) const;  // true if entry can be found in the array

  T& get(const T& entry);  // return a reference to entry in the tree
  const T& get(const T& entry) const;  // return a reference to entry in the
                                       // tree
  T& get_existing(const T& entry);  // return a reference to entry in the tree
  const T& get_existing(const T& entry) const;  // return a reference to entry in the tree

  Iterator find(
      const T& entry);  // return an iterator to this key. NULL if not there.

  Iterator lower_bound(const T& key);  // return first that goes NOT BEFORE
                                       // key entry or next if does not
                                       // exist >= entry
  Iterator upper_bound(const T& key);  // return first that goes AFTER key
  int size() const;    // count the number of elements in the tree
  bool empty() const;  // true if the tree is empty

  void print_tree(int level = 0, std::ostream& outs = std::cout)
      const;  // print a readable version of the tree
  friend std::ostream& operator<<(std::ostream& outs,
                                  const BPlusTree<T>& print_me) {
    print_me.print_tree(0, outs);
    return outs;
  }
  friend BPlusTree<T>& operator+=(BPlusTree<T>& list, const T& addme) {
    list.insert(addme);
    return list;
  }
  bool is_valid();

  void print_as_list(std::ostream& outs = std::cout) const;
  void print_as_vector(std::ostream& outs = std::cout) const;

  Iterator begin();
  Iterator end();

 private:
  static const int MINIMUM = 1;
  static const int MAXIMUM = 2 * MINIMUM;

  bool ignore_dups;                    // true if duplicate keys may be inserted
  int data_count;                  // number of data elements
  T data[MAXIMUM + 1];             // holds the keys
  int child_count;                 // number of children
  BPlusTree* subset[MAXIMUM + 2];  // subtrees
  BPlusTree* next;
  bool is_leaf() const {
    return child_count == 0;
  }  // true if this is a leaf node

  T* find_ptr(
      const T& entry);  // return a pointer to this key. NULL if not there.

  // insert element functions
  bool loose_insert(
      const T& entry);     // allows MAXIMUM+1 data elements in the root
  void fix_excess(int i);  // fix excess of data elements in child i

  // remove element functions:
  bool loose_remove(
      const T& entry);  // allows MINIMUM-1 data elements in the root

  BPlusTree<T>* fix_shortage(
      int i);  // fix shortage of data elements in child i
               // and return the smallest key in this subtree
  BPlusTree<T>* get_smallest_node();
  
  void get_smallest(T& entry);    // entry := leftmost leaf
  void get_biggest(T& entry);     // entry := rightmost leaf
  void remove_biggest(T& entry);  // remove the biggest child of this
                                  // tree->entry
  void transfer_left(int i);      // transfer one element LEFT from child i
  void transfer_right(int i);     // transfer one element RIGHT from child i
  BPlusTree<T>* merge_with_next_subset(int i);  // merge subset i with subset
                                                // i+1
  void copy_tree(const BPlusTree<T>& other, BPlusTree<T>*& last_node);
};

//---------------------------------------------------------------------
//            C T O R  /  B I G   T H R E E
//---------------------------------------------------------------------

template <typename T>
BPlusTree<T>::BPlusTree(bool ignore)
    : ignore_dups(ignore), data_count(0), child_count(0), next(NULL) {
  // left emtpy
}

template <typename T>
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other)
    : data_count(0), child_count(0), next(NULL) {
  copy(other);
}

template <typename T>
BPlusTree<T>::~BPlusTree() {
  const bool debug = false;
  if (debug) cout << "** destructor fired!" << endl;
  clear_tree();
}

template <typename T>
BPlusTree<T>& BPlusTree<T>::operator=(const BPlusTree<T>& RHS) {
  const bool debug = false;
  if (debug) cout << "** assignment operator fired!" << endl;
  copy(RHS);
  return *this;
}

//---------------------------------------------------------------
//      P R I N T
//---------------------------------------------------------------
template <typename T>
void BPlusTree<T>::print_tree(int level, ostream& outs) const {
  // 1. print the last child (if any)
  int i = data_count;
  if (!is_leaf()) {
    subset[i]->print_tree(level + 4, outs);
  }
  i--;
  // 2. print all the rest of the data and children
  while (i >= 0) {
    outs << setw(level) << "" << data[i] << endl;
    if (!is_leaf()) {
      subset[i]->print_tree(level + 4, outs);
    }
    i--;
  }
}

template <typename T>
void BPlusTree<T>::print_as_list(std::ostream& outs) const {
  if(!is_leaf()) {
  for(int i=0;i<child_count;++i) {
    subset[i]->print_as_list();
  }
  } else {
    for(int i=0;i<data_count;++i) {
      outs << data[i] << endl;
    }
  }
}

template <typename T>
void BPlusTree<T>::print_as_vector(std::ostream& outs) const {
  if(!is_leaf()) {
  for(int i=0;i<child_count;++i) {
    subset[i]->print_as_vector();
  }
  } else {
    for(int i=0;i<data_count;++i) {
      outs << data[i] << " ";
    }
  }
}

//------------------------------------------------
//          I N S E R T
//------------------------------------------------
template <typename T>
bool BPlusTree<T>::insert(const T& entry) {
  // start by calling loose_insert
  bool newInsert = loose_insert(entry);
  // if duplicate was overridden
  if (!newInsert) {
    return false;
  }
  // fix root if it's fat
  if (data_count > MAXIMUM) {
    // create a new node
    BPlusTree<T>* newNode = new BPlusTree<T>(ignore_dups);
    // copy data and children to new node
    copy_array(newNode->data, data, newNode->data_count, data_count);
    copy_array(newNode->subset, subset, newNode->child_count, child_count);

    // clear out root
    data_count = 0;
    child_count = 0;

    // set new ptr as the child of root
    subset[0] = newNode;
    child_count++;

    // fix the child
    fix_excess(0);
  }
  return newInsert;
}

template <typename T>
bool BPlusTree<T>::loose_insert(const T& entry) {
  int i = first_ge(data, data_count, entry);
  bool found = (i < data_count && data[i] == entry);

  if (found) {
    // ignore duplicate if ignore_dups is true
    if (ignore_dups) {
      return false;
    }
    if (is_leaf()) {
      // deal with duplicates: call +=
      data[i] += entry;
      return false;
    } else {
      subset[i + 1]->loose_insert(entry);
      if (subset[i + 1]->data_count > MAXIMUM) {
        fix_excess(i + 1);
      }
      return false;
    }
  }
  // if not found and leaf
  if (is_leaf()) {
    insert_item(data, i, data_count, entry);
    return true;
  }
  // if not found and !leaf use recursion
  bool notDuplicate = subset[i]->loose_insert(entry);
  // fix subtree if it has excess entries
  if ((subset[i]->data_count) > MAXIMUM) {
    fix_excess(i);
  }
  return notDuplicate;
}

template <typename T>
void BPlusTree<T>::fix_excess(int i) {
  // create new subset
  BPlusTree<T>* temp = new BPlusTree<T>(ignore_dups);

  // insert a new child
  insert_item(subset, i + 1, child_count, temp);

  // move half of subset[i]'s data to new subset
  split(subset[i]->data, subset[i]->data_count, subset[i + 1]->data,
        subset[i + 1]->data_count);

  // move half of subset[i]'s children to new subset
  split(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset,
        subset[i + 1]->child_count);

  // insert middle into root's data
  T detached;
  detach_item(subset[i]->data, subset[i]->data_count, detached);
  ordered_insert(data, data_count, detached);

  // if leaf insert middle into subset and fix pointers
  if (subset[i]->is_leaf()) {
    insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, detached);
    subset[i + 1]->next = subset[i]->next;
    subset[i]->next = subset[i + 1];
  }
}

//------------------------------------------------
//          R E M O V E
//------------------------------------------------
template <typename T>
bool BPlusTree<T>::remove(const T& entry) {
  /*
   * ---------------------------------------------------------------------------------
   * Same as BTree:
   * Loose_remove the entry from this tree.
   * Shrink if you have to
   * ---------------------------------------------------------------------------------
   * once you return from loose_remove, the root (this object) may have no data
   * and only a single subset: now, the tree must shrink:
   *
   * point a temporary pointer (shrink_ptr) and point it to this root's only
   * subset copy all the data and subsets of this subset into the root (through
   * shrink_ptr) now, the root contains all the data and poiners of it's old
   * child. now, simply delete shrink_ptr, and the tree has shrunk by one level.
   * Note, the root node of the tree will always be the same, it's the
   * child node we delete
   *
   *
   */

  // if entry was not found
  if (!loose_remove(entry)) {
    return false;
  }
  // if root is empty with a child, shrink the tree
  if ((data_count == 0) && (child_count == 1)) {
    BPlusTree<T>* shrink_ptr = subset[0];
    // copy data up to root
    copy_array(data, shrink_ptr->data, data_count, shrink_ptr->data_count);

    // copy children up to root
    child_count = 0;
    for (int i = 0; i < shrink_ptr->child_count; ++i) {
      subset[i] = shrink_ptr->subset[i];
      child_count++;
    }
    shrink_ptr->child_count = 0;
    delete shrink_ptr;
  }
  return true;
}

template <typename T>
bool BPlusTree<T>::loose_remove(const T& entry) {
  /* four cases:
        leaves:
             a. not found: there is nothing to do
             b. found    : just remove the target
        non leaf:
             c. not found: subset[i]->loose_remove, fix_shortage(i)
             d. found    : subset[i+1]->loose_remove, fix_shortage(i+1) [...]
                 (No More remove_biggest)

          |   !found               |   found                 |
    ------|------------------------|-------------------------|-------
    leaf  |  a: nothing            | b: delete               |
          |     to do              |    target               |
    ------|------------------------|-------------------------|-------
    !leaf | c:                     | d: B_PLUS_TREE          |
          |  [i]->  loose_remove   |   [i+1]-> loose_remove  |
          |  fix_shortage(i)       | fix_shortage(i+1) [...] |
    ------|------------------------|-------------------------|-------


  */
  const bool debug = false;
  int i = first_ge(data, data_count, entry);
  bool found = (i < data_count && data[i] == entry);
  T found_entry;
  if (is_leaf()) {
    if (!found) {
      //[a.] nothing to do
      // entry not in this tree
      return false;
    } else {
      //[b.] just delete the item
      //   my parent will take care of my shortage
      T deleted;
      delete_item(data, i, data_count, deleted);
      return true;
    }

  } else {
    // not leaf:
    // ---- 000 B_PLUS_TREE: no more remove_biggest
    if (!found) {
      //[c.] Not here: subset[i]->loose_remove
      // not found yet. search in the next level:
      found = subset[i]->loose_remove(entry);
      if (subset[i]->data_count < MINIMUM) {
        fix_shortage(i);
      }
      return found;
    } else {
      //[d.] found key in an inner node:subset[i+1]->loose_remove
      assert(i < child_count - 1);
      subset[i + 1]->loose_remove(entry);
      if (subset[i + 1]->data_count < MINIMUM) {
        fix_shortage(i + 1);
      }
      // look for data[i]'s new position
      i = first_ge(data, data_count, entry);
      found = (i < data_count && data[i] == entry);
      if (found) {
        // replace with smallest
        subset[i + 1]->get_smallest(data[i]);
      } else {
        // search in subset[i]->data and replace
        int j = first_ge(subset[i]->data, subset[i]->data_count, entry);
        found = (j < subset[i]->data_count && subset[i]->data[j] == entry);
        // replace with subset[i+1]->smallest
        if (found) {
          subset[i]->subset[j + 1]->get_smallest(subset[i]->data[j]);
        }
      }
      /*
       * Here's The Story:
       * data[i] is the same as the item that we have deleted.
       * so, now, it needs to be replaced by the current smallest key
       *      in subset[i+1]
       * Problem: After fix_shortage, data[i] could have moved to a different
       * index(?) or it could have sunk down to a lower level as a result of
       * merge we need to find this item and replace it.
       *
       *      Before fix_shortage: we cannot replace data[i] with
       * subset[i+1]->smallest before fix_excess because this smallest key could
       * be the very entry we are removing. So, we'd be replacing data[i] with
       * entry. and this will leave the deleted key in the inner nodes.
       *
       *      After fix_shortage: We have no way of knowing where data[i] key
       * (which is same as entry) will end up. It could move down one level by
       * the time fix_shortage returns.
       *
       *      Therefore it seems like we have no choice but to search for it in
       *      data[ ] AND subset[i]->data[ ]
       * Current Solution: Kind of messy:
       *      After fix_shortage(i+1):
       *      Search for entry in data[ ] and if found, replace it with
       * smallest. otherwise, search for it in subset[i]->data[ ] and replace
       * it. that's where the key (entry) will end up after fix order returns
       * (credit: Jiaruy Li)
       *
       */

      // remember. it's possible that data[i] will be gone by the time
      //      fix_shortage returns.
      // key was removed from subset[i+1]:
      //  1. shortage: find entry in data or subset[i+1]->data
      //              and replace it with subset[i+1]->smallest
      //  2. no shortage: replace data[i] with subset[i+1]->smallest
      return true;
    }
    // --------------------------------------------------------
  }
}

template <typename T>
BPlusTree<T>* BPlusTree<T>::fix_shortage(int i) {
  /*
   * fix shortage in subtree i:
   * if child i+1 has more than MINIMUM,
   *          (borrow from right) transfer / rotate left(i+1)
   * elif child i-1 has more than MINIMUM,
   *          (borrow from left) transfer /rotate right(i-1)
   * elif there is a left sibling,
   *          merge with prev child: merge(i-1)
   * else
   *          merge with next (right) child: merge(i)
   *
   *
   * returns a pointer to the fixed_subset
   */
  const bool debug = false;
  if ((i < child_count - 1) && (subset[i + 1]->data_count > MINIMUM)) {
    // borrow from right subtree if you can
    transfer_left(i + 1);
  } else if (i > 0 && subset[i - 1]->data_count > MINIMUM) {
    // borrow from left subtree if it has more than MINIMUM
    transfer_right(i - 1);
  } else if (i > 0) {
    // merge with left if there is a left
    merge_with_next_subset(i - 1);
  } else {
    // merge with right
    merge_with_next_subset(i);
  }
  return subset[i];
}

// returns smallest node in the tree
template <typename T>
BPlusTree<T>* BPlusTree<T>::get_smallest_node() {
  if (is_leaf()) {
    return this;
  }
  // recursive call if !leaf
  return subset[0]->get_smallest_node();
}

template <typename T>
void BPlusTree<T>::get_smallest(T& entry) {
  // replace entry with the left_most leaf of this tree
  // Keep looking in the first subtree (recursive)
  //  until you get to a leaf.
  // Then, replace entry with data[0] of the leaf node
  const bool debug = false;
  if (child_count != 0) {
    subset[0]->get_smallest(entry);
  } else {
    assert(data_count > 0);
    entry = data[0];
  }
}

template <typename T>
BPlusTree<T>* BPlusTree<T>::merge_with_next_subset(int i) {
  /*
   * ----------------------------------------------------------------------
   *  Merge subset[i] with subset [i+1] REMOVE data[i];
   *  non leaf: same as BTree
   *  leaves  : delete but do not bring down data[i]
   * ----------------------------------------------------------------------
   *
   *   1. remove data[i] from this object
   *   2. if not a leaf, append it to child[i]->data:
   *   3. Move all data items from subset[i+1]->data to right of subset[i]->data
   *   4. Move all subset pointers from subset[i+1]->subset to
   *          right of subset[i]->subset
   *   5. delete subset[i+1] (store in a temp ptr)
   *   6. if a leaf, point subset[i]->next to temp_ptr->next
   *   6. delete temp ptr
   *
   *
   * non-leaf nodes: (same as BTree)
   * ------------------
   *  i = 0:
   *             [50  100]
   *          /      |     \
   *  [  ]         [75]       ....
   *    |         /    \
   *   [a]      [b]    [c]
   *
   *  bring down data[i], merge it with subset[i] and subset[i+1]:
   *      then, get rid of subset[i+1]
   *             [100]
   *               |
   *            [50|75]       ....
   *            /  |  \
   *         [a]  [b]  [c]
   *
   *
   *
   * leaf node:
   * ----------------
   * Exactly the same, but do not attach the deleted data[i] to subset[i]->data[
   * ]
   *
   *  i = 0 : merge 5 and [()]
   *        [7 | 10]
   *      /    |     \
   *  [5]->   [()]->  [10]
   *
   *  Delete data[i] (7), merge subset[i] and subset[i+1]
   *      WITHOUT bringing down data[i]
   *
   *        [10]
   *      /      \
   *  [5]->      [10]
   *
   *
   * i = 1 merge 7 and [()]
   *        [7 | 10]
   *      /    |     \
   *  [5]->   [7]->  [()]
   *
   *  Delete data[i] (10), merge subset[i] and subset[i+1]
   *      WITHOUT bringing down data[i]
   *
   *        [7]
   *      /     \
   *  [5]->      [7]
   *
   *
   *
   *
   */
  const bool debug = false;

  // remove data[i]
  T temp;
  delete_item(data, i, data_count, temp);

  if (!subset[i]->is_leaf()) {
    // bring original data[i] down to subset[i]'s data
    ordered_insert(subset[i]->data, subset[i]->data_count, temp);
  }

  // merge data
  cg::merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data,
            subset[i + 1]->data_count);

  // merge children
  if (!subset[i]->is_leaf()) {
    cg::merge(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset,
              subset[i + 1]->child_count);
  }

  // delete subset[i+1] and shift other subsets if needed
  BPlusTree<T>* temp_ptr;
  delete_item(subset, i + 1, child_count, temp_ptr);

  // fix next pointer if leaf
  if (subset[i]->is_leaf()) {
    subset[i]->next = temp_ptr->next;
  }

  delete temp_ptr;

  return subset[i];
}

template <typename T>
void BPlusTree<T>::transfer_left(int i) {
  /*
   * --------------------------------------------------------------
   * transfer_left: from subset[i] to subset[i-1]
   *      non-leaf: same as BTree
   *      leaves  : rotate and leave and update data[i-1] with
   * subset[i]->data[0] leftmost key after you borrowed goes to replace
   * data[i-1]
   * --------------------------------------------------------------
   *
   * non-leaf keys: BTree's rotate_left
   * ---------------
   *
   * (0 < i < child_count) and (subset[i]->data_count > MINIMUM)
   * subset[i-1] has only MINIMUM - 1 entries.
   *
   * item transfers from child[i] to child [i-1]
   *
   * FIRST item of subset[i]->data moves up to data to replace data[i-1],
   * data[i-1] moves down to the RIGHT of subset[i-1]->data
   *
   *  i = 1:
   *              [50  100]
   *  [  ]         [65 75]       ....
   *   [a]      [b]  [c]  [d]
   *
   *  65 move up to replace 50 (data[i])
   *  65's child (its child 0) moves over to be the future child of 50
   *  50 moves down to the right of subset[i]->data
   *
   *               [65 100]
   *   [50]         [ 75 ]       ....
   * [a]  [b]      [c]  [d]
   *
   * ****This does not belong here:
   * last item of subset[i-1]->data moves up to data to replace data[i],
   * data[i] moves down to the RIGHT of subset[i]->data
   *
   * leaf keys:
   * -------------
   *  fix_shortage(0) calls trnasfer_left(1) so, i = 1
   *          [7 | 10]
   *        /    |     \
   * [( )]<=[(7) | 8]  [10]
   *
   * 1. transfer subset[i(1)]->data[0] to end of subset[i-1]
   *        [7 | 10]
   *      /    |     \
   *   [7]    [8]   [10]
   *
   * 2. update parent of the transfered subset: data[i-1 (0)] =
   * subset[i(1)]->data[0]
   *
   *        [(8) | 10]
   *      /      |     \
   *   [7]     [(8)]   [10]
   *
   *
   *
   */
  // same as btree if subset is not a leaf
  if (!subset[i]->is_leaf()) {
    // move data[i-1] to subset[i-1]'s data
    T removed;
    delete_item(data, i - 1, data_count, removed);
    attach_item(subset[i - 1]->data, subset[i - 1]->data_count, removed);

    // move subset[i]'s smallest data to replace data[i-1]
    delete_item(subset[i]->data, 0, subset[i]->data_count, removed);
    insert_item(data, i - 1, data_count, removed);

    // transfer smallest child of subset[i] to subset[i-1]
    BPlusTree<T>* removed_child;
    delete_item(subset[i]->subset, 0, subset[i]->child_count, removed_child);
    attach_item(subset[i - 1]->subset, subset[i - 1]->child_count,
                removed_child);
  }
  // if subset is a leaf
  else {
    // transfer subset[i]->data[0] to the end of subset[i-1]
    T transfer;
    delete_item(subset[i]->data, 0, subset[i]->data_count, transfer);
    attach_item(subset[i - 1]->data, subset[i - 1]->data_count, transfer);

    // update parent
    data[i - 1] = subset[i]->data[0];
  }
}

template <typename T>
void BPlusTree<T>::transfer_right(int i) {
  /*
   * --------------------------------------------------------------
   * transfer right from subset[i] to subset[i+1]
   *      non-leaf: same as BTree
   *      leaves  : rotate and leave a 'trace':
   *              data[i] is replaced with subset[i+1]->data[0]
   *              after you borrowed the key,
   * --------------------------------------------------------------
   *
   * non-leaf keys: BTree's rotate_right
   * ---------------
   * (i < child_count - 1) and (subset[i-1]->data_count > MINIMUM)
   * subset[i+ 1] has only MINIMUM - 1 entries.
   *
   * item transfers from child[i] to child [i+1]
   *
   * LAST item of subset[i]->data moves up to data to replace data[i],
   * data[i] moves down to the LEFT of subset[i+1]->data
   *
   * i = 1
   *                     [50 100]
   *      [20 30]        [65 75]          [ ]
   *  [..] [..] [..]   [a] [b] [c]        [..]
   *
   *  75 moves up to replace 100 (data[i])
   *  75's child (its last child) moves over to be the (child 0) child of 100
   *  100 moves down to subset[i]->data
   *
   *                     [50 75]
   *      [20 30]          [65]          [100]
   *  [..] [..] [..]     [a] [b]        [c] [..]
   *
   * last item of subset[i-1]->data moves up to data,
   * data[i] moves down to the RIGHT of subset[i]->data
   *
   * leaf keys:
   * -------------
   *  fix_shortage(2) calls trnasfer_right(1) so, i = 1 subset[i] is ([7|8])
   *  subset[i+1] is the one being fixed.
   *        [7 | 10]
   *      /    |     \
   * [5|6]->[7 | (8)]=>[()]
   *
   * 1. transfer subset[i(1)]->data[last item] to left of subset[i+1]->data
   *        [7 | (10)]
   *      /    |     \
   *   [5|6]->[7]-> [8]
   *
   * 2. update parent of the transfered subset: data[i (1)] =
   * subset[i+1(2)]->data[0]
   *
   *        [7 | 8]
   *      /    |    \
   *   [5|6]->[7]-> [8]
   *
   *
   */

  const bool debug = false;

  // same as btree if subset is not a leaf
  if (!subset[i]->is_leaf()) {
    // detach from subset[i]
    T detached;
    detach_item(subset[i]->data, subset[i]->data_count, detached);
    // remove data[i]
    T removed;
    delete_item(data, i, data_count, removed);
    // insert the detached item at data[i]
    insert_item(data, i, data_count, detached);
    // insert the removed item in subset[i+1]'s data[0]
    insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, removed);

    // move last child of subset[i] to be subset[i+1]'s first child
    BPlusTree<T>* detached_child;
    detach_item(subset[i]->subset, subset[i]->child_count, detached_child);
    insert_item(subset[i + 1]->subset, 0, subset[i + 1]->child_count,
                detached_child);
  }
  // if subset is a leaf
  else {
    // transfer subset[i]'s last data item to subset[i+1]
    T transfer;
    detach_item(subset[i]->data, subset[i]->data_count, transfer);
    insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, transfer);
    // update parent
    data[i] = transfer;
  }
}

//---------------------------------------------------------------------
//            B E G I N ( )   &   E N D ( )
//---------------------------------------------------------------------

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::begin() {
  return Iterator(get_smallest_node());
}
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::end() {
  return Iterator(NULL);
}

// true if entry can be found in the array
template <typename T>
bool BPlusTree<T>::contains(const T& entry) const {
  int i = first_ge(data, data_count, entry);
  bool found = (i < data_count && data[i] == entry);
  // make sure data is found in a leaf node
  if (!is_leaf()) {
    if (found) {
      return subset[i + 1]->contains(entry);
    }
    return subset[i]->contains(entry);
  } else {
    return found;
  }
}

template <typename T>
T& BPlusTree<T>::get(const T& entry) {
  // If entry is not in the tree, add it to the tree

  const bool debug = false;
  if (!contains(entry)) 
  insert(entry);

  return get_existing(entry);
}

template <typename T>
const T& BPlusTree<T>::get(const T& entry) const {
  // If entry is not in the tree, add it to the tree
  // assert(contains(entry));

  const bool debug = false;
  assert(contains(entry));

  return get_existing(entry);
}

template <typename T>
T& BPlusTree<T>::get_existing(const T& entry) {
  /*
   * ---------------------------------------------------------------
   * This routing explains plainly how the BPlusTree is organized.
   * i = first_ge
   *       |      found         |    !found         |
   * ------|--------------------|-------------------|
   * leaf  |  you're done       | it's not there    |
   *       |                    |                   |
   * ------|--------------------|-------------------|
   * !leaf | subset[i+1]->get() |  subset[i]->get() |
   *       | (inner node)       |                   |
   * ------|--------------------|-------------------|
   *       |                    |                   |
   *
   * ---------------------------------------------------------------
   *
   */
  // assert that entry is not in the tree.
  // assert(contains(entry));

  const bool debug = false;
  int i = first_ge(data, data_count, entry);
  bool found = (i < data_count && data[i] == entry);
  if (is_leaf()) {
    if (found) {
      return data[i];
    } else {
      if (debug)
        cout << "get_existing was called with nonexistent entry" << endl;
      assert(found);
    }
  }
  if (found)  // inner node
    return subset[i + 1]->get(entry);
  else  // not found yet...
    return subset[i]->get(entry);
}

template <typename T>
const T& BPlusTree<T>::get_existing(const T& entry) const {
  /*
   * ---------------------------------------------------------------
   * This routing explains plainly how the BPlusTree is organized.
   * i = first_ge
   *       |      found         |    !found         |
   * ------|--------------------|-------------------|
   * leaf  |  you're done       | it's not there    |
   *       |                    |                   |
   * ------|--------------------|-------------------|
   * !leaf | subset[i+1]->get() |  subset[i]->get() |
   *       | (inner node)       |                   |
   * ------|--------------------|-------------------|
   *       |                    |                   |
   *
   * ---------------------------------------------------------------
   *
   */
  // assert that entry is not in the tree.
  // assert(contains(entry));

  const bool debug = false;
  int i = first_ge(data, data_count, entry);
  bool found = (i < data_count && data[i] == entry);
  if (is_leaf()) {
    if (found) {
      return data[i];
    } else {
      if (debug)
        cout << "get_existing was called with nonexistent entry" << endl;
      assert(found);
    }
  }
  if (found)  // inner node
    return subset[i + 1]->get(entry);
  // or just return true?
  else  // not found yet...
    return subset[i]->get(entry);
}

// return an iterator to this key. NULL if not there.
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::find(const T& entry) {
  int i = first_ge(data, data_count, entry);
  bool found = (i < data_count && data[i] == entry);
  if (!is_leaf()) {
    if (found) {
      return subset[i + 1]->find(entry);
    }
    return subset[i]->find(entry);
  } else {
    if (found) {
      Iterator it(this, i);
      return it;
    } else {
      Iterator it;
      return it;
    }
  }
}

// return first that goes NOT BEFORE
// key entry or next if does not
// exist >= entry
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::lower_bound(const T& key) {
  int i = first_ge(data, data_count, key);
  bool found = (i < data_count && data[i] == key);
  if (!is_leaf()) {
    return subset[i]->lower_bound(key);
  } else {
    if (i < data_count) {
      Iterator it(this, i);
      return it;
    } else {
      Iterator it(this, data_count - 1);
      while (it.it->data[it.key_ptr] < key) {
        if(!it.it->next) {
          it = Iterator();
          return it;
        }
        it++;
      }
      return it;
    }
  }
}

// return first that goes AFTER key
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::upper_bound(const T& key) {
  // search for key
  int i = first_ge(data, data_count, key);
  bool found = (i < data_count && data[i] == key);
  // use recursive call until is_leaf
  if (!is_leaf()) {
    if (found) {
      return subset[i + 1]->upper_bound(key);
    }
    return subset[i]->upper_bound(key);
  } else {
    if (i < data_count) {
      Iterator it(this, i);
      // increment until greater than key
      while (it.it->data[it.key_ptr] <= key) {
        it++;
        if(it.is_null()) {
          it = Iterator();
          return it;
        }
      }
      return it;
    } else {
      Iterator it(this,i-1);
      while (it.it->data[it.key_ptr] <= key) {
        if(!it.it->next) {
          it = Iterator();
          return it;
        }
        it++;
      }
      return it;
    }
  }
}

template <typename T>
bool BPlusTree<T>::is_valid() {
  // should check that every data[i] < data[i+1]
  for(int i=1;i<data_count;++i) {
    assert(data[i]==maximal(data[i-1],data[i]));
  }
  if (is_leaf()) return true;

  // data[data_count-1] must be less than equal to
  //  every subset[child_count-1]->data[ ]
  assert(is_le(subset[child_count - 1]->data,
               subset[child_count - 1]->data_count, data[data_count - 1]));

  // every data[i] is greater than every subset[i]->data[ ]
  for (int i = 0; i < data_count; ++i) {
    assert(is_gt(subset[i]->data, subset[i]->data_count, data[i]));
  }

  // B+Tree: Every data[i] is equal to subset[i+1]->smallest
  for (int i = 0; i < data_count; ++i) {
    T small;
    subset[i + 1]->get_smallest(small);
    assert(data[i] == small);
  }

  // Recursively validate every subset[i]
  for (int i = 0; i < child_count; ++i) {
    subset[i]->is_valid();
  }

  return true;
}

template <typename T>
T* BPlusTree<T>::find_ptr(const T& entry) {
  int i = first_ge(data, data_count, entry);
  bool found = (i < data_count && data[i] == entry);
  if (!is_leaf()) {
    if (found) {
      return subset[i + 1]->find_ptr(entry);
    }
    return subset[i]->find_ptr(entry);
  } else {
    T* found_ptr = new T();
    if (found) {
      found_ptr = &data[i];
    } else {
      found_ptr = nullptr;
    }
    return found_ptr;
  }
}

//---------------------------------------------------------------
//      S I Z E  /  E M P T Y
//---------------------------------------------------------------
template <typename T>
int BPlusTree<T>::size() const {
  // this function counts the number of keys in the btree
  int size = 0;
  if (is_leaf()) {
    size += data_count;
    return size;
  } else {
    for (int i = 0; i < child_count; ++i) {
      size += subset[i]->size();
    }
  }
  return size;
}

template <typename T>
bool BPlusTree<T>::empty() const {
  return (data_count == 0);
}

//---------------------------------------------------------------
//      C L E A R   /  C O P Y
//---------------------------------------------------------------

// clear this object (delete all nodes etc.)
template <typename T>
void BPlusTree<T>::clear_tree() {
  if (!is_leaf()) {
    for (int i = 0; i < child_count; i++) {
      subset[i]->clear_tree();
    }
    for (int i = 0; i < child_count; ++i) {
      delete subset[i];
      subset[i] = nullptr;
    }
  }
  next = nullptr;
  data_count = 0;
  child_count = 0;
}

// copy other into this object
template <typename T>
void BPlusTree<T>::copy(const BPlusTree<T>& other) {
  // assumes this btree is empty. [memory leaks otherwise]
  //assert(empty());
  if(!empty()) {
    clear_tree();
  }
  BPlusTree<T>* ln = nullptr;
  copy_tree(other,ln);
}

template <typename T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other, BPlusTree<T>*& last_node) {
  // copy data
  ignore_dups = other.ignore_dups;
  copy_array(data, other.data, data_count, other.data_count);
  // copy children
  for (int i = 0; i < other.child_count; ++i) {
    subset[i] = new BPlusTree<T>;
    subset[i]->copy_tree(*other.subset[i],last_node);
  }
  child_count = other.child_count;
  if(is_leaf()) {
    if(last_node==nullptr) {
      last_node = this;
    } else {
      last_node->next = this;
      last_node = this;
    }
  }
  }


#endif  // B_PLUS_TREE_H_
