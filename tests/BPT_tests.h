#ifndef BPT_TESTS_H_
#define BPT_TESTS_H_

#include <ctime>
#include <iostream>
#include <random>

#include "../includes/sort_functions.h"
#include "../includes/data_structures/B+Tree.h"

// Important Tests
void test_bplustree_auto(int tree_size = 5000, int how_many = 500,
                         bool report = false);
bool test_bplustree_auto(int how_many, bool report = true);
void test_iterator();

// Other Small Tests
void insertion_test();
void iterator_test();
void copy_clear_test();
void contains_get_test();
void iterator_search_test();
void removal_test1();
void removal_test2();
void mass_insertion_deletion_test();
void map_test();
void map_interactive_test();
void mmap_test();
void mmap_interactive_test();

int Random(int lo, int hi) {
  int r = rand() % (hi - lo + 1) + lo;

  return r;
}

void test_bplustree_auto(int tree_size, int how_many, bool report) {
  bool verified = true;
  for (int i = 0; i < how_many; i++) {
    if (report) {
      cout << "*********************************************************"
           << endl;
      cout << " T E S T:    " << i << endl;
      cout << "*********************************************************"
           << endl;
    }
    if (!test_bplustree_auto(tree_size, report)) {
      cout << "T E S T :   [" << i << "]    F A I L E D ! ! !" << endl;
      verified = false;
      return;
    }
  }
  cout << "********************************************************************"
          "******"
       << endl;
  cout << "********************************************************************"
          "******"
       << endl;
  cout << "             E N D     T E S T: " << how_many << " tests of "
       << tree_size << " items: ";
  cout << (verified ? "VERIFIED" : "VERIFICATION FAILED") << endl;
  cout << "********************************************************************"
          "******"
       << endl;
  cout << "********************************************************************"
          "******"
       << endl;
}

bool test_bplustree_auto(int how_many, bool report) {
  const int MAX = 10000;
  assert(how_many < MAX);
  BPlusTree<int> bpt(true);
  int a[MAX];
  int original[MAX];
  int deleted_list[MAX];

  int original_size = 0;
  int size = 0;
  int deleted_size = 0;

  // fill a[ ]
  for (int i = 0; i < how_many; i++) {
    a[i] = i;
    size++;
  }
  // shuffle a[ ]: Put this in a function!
  shuffle(a, size);

  // copy  a[ ] -> original[ ]:
  copy_array(original, a, original_size, size);

  for (int i = 0; i < size; i++) {
    bpt.insert(a[i]);
  }
  if (report) {
    cout << "========================================================" << endl;
    cout << "  " << endl;
    cout << "========================================================" << endl;
    cout << bpt << endl << endl;
  }
  for (int i = 0; i < how_many; i++) {
    int r = Random(0, how_many - i - 1);
    if (report) {
      cout << "========================================================"
           << endl;
      cout << bpt << endl;
      cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . "
           << endl;
      cout << "deleted: ";
      cg::print_array(deleted_list, deleted_size);
      cout << "   from: ";
      cg::print_array(original, original_size);
      cout << endl;
      cout << "  REMOVING [" << a[r] << "]" << endl;
      cout << "========================================================"
           << endl;
    }
    bpt.remove(a[r]);

    delete_item(a, r, size, deleted_list[deleted_size++]);
    if (!bpt.is_valid()) {
      cout << setw(6) << i << " I N V A L I D   T R E E" << endl;
      cout << "Original Array: ";
      cg::print_array(original, original_size);
      cout << "Deleted Items : ";
      cg::print_array(deleted_list, deleted_size);
      cout << endl << endl << bpt << endl << endl;
      return false;
    }
  }
  if (report) cout << " V A L I D    T R E E" << endl;

  return true;
}

void test_iterator() {
  const bool debug = false;
  BPlusTree<int> bpt(true);
  for (int i = 0; i < 125; i++) {
  bpt.insert(Random(0, 100));
  }
  cout << bpt << endl;

  cout << "------------------------------------------------------------"
       << endl;
  for (BPlusTree<int>::Iterator it = bpt.begin(); it != bpt.end(); ++it) {
    if (debug) it.print_Iterator();
    cout << "[" << *it << "] ";
    if (debug) cout << endl;
  }
  cout << endl;
  cout << "------------------------------------------------------------"
       << endl;
  cout << "test ++ operator: " << endl;
  BPlusTree<int>::Iterator it = bpt.begin();
  cout << "{" << *(it++) << "}" << endl;
  cout << "{" << *it << "}" << endl;
  for (int i = 60; i < 75; i++) {
    it = bpt.find(i);
    if (!it.is_null())
      cout << *it << " was found." << endl;
    else
      cout << i << " was not found" << endl;
  }
  cout << "===================================================================="
       << endl;
}

void insertion_test() {
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tI N S E R T I O N  T E S T\n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;
  srand(time(0));
  BPlusTree<int> bpt(true);
  int inserted_item;
  for (int i = 0; i < 15; ++i) {
    inserted_item = rand() % 100;
    cout << "Inserting " << inserted_item << endl << endl;
    bpt.insert(inserted_item);
    cout << bpt << endl;
    bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
  }
  cout << "Size: " << bpt.size() << endl;
  cout << "\n\n----------------END TEST---------------\n\n";
}

void iterator_test() {
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tI T E R A T O R  T E S T\n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;
  BPlusTree<string> bpt(true);
  bpt.insert("dog");
  bpt.insert("cat");
  bpt.insert("monkey");
  bpt.insert("panda");
  bpt.insert("horse");
  bpt.insert("bird");
  bpt.insert("goat");
  BPlusTree<string>::Iterator It;
  cout << "Tree: " << endl << endl;
  cout << bpt << endl << endl;
  bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
  for (It = bpt.begin(); !It.is_null(); ++It) {
    cout << "Iterator: ";
    cout << *It << endl << endl;
    cout << "Iterator++\n\n";
  }
  cout << "\n\n----------------END TEST---------------\n\n";
}

void copy_clear_test() {
  for (int i = 0; i < 42; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tC O P Y/C L E A R  T E S T\n";
  for (int i = 0; i < 42; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  // Let's start by making a random tree
  BPlusTree<int> bpt(true);
  srand(time(0));
  for (int i = 0; i < 10; ++i) {
    bpt.insert((rand() / 7) % 100);
  }
  cout << "INITIAL TREE:\n\n";
  cout << bpt << endl << endl;
  bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";

  // test copy constructor
  BPlusTree<int> bpt2(bpt);
  cout << "SECOND TREE (COPY CONSTRUCTOR):\n\n";
  cout << bpt2 << endl << endl;
  bpt2.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";

  // make changes to one tree
  cout << "CHANGING FIRST TREE\n\n";
  bpt.insert(rand() % 100);
  bpt.insert(rand() % 100);
  bpt.insert(rand() % 100);

  cout << "FIRST TREE:\n\n";
  cout << bpt << endl << endl;
  bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
  cout << "SECOND TREE:\n\n";
  cout << bpt2 << endl << endl;
  bpt2.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";

  // test clear
  cout << "CLEARING SECOND TREE:\n\n";
  bpt2.clear_tree();

  cout << "FIRST TREE:\n\n";
  cout << bpt << endl << endl;
  bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
  cout << "SECOND TREE:\n\n";
  cout << bpt2 << endl << endl;
  bpt2.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";

  // test empty
  if (bpt.empty()) {
    cout << "FIRST TREE IS EMPTY\n\n";
  } else {
    cout << "FIRST TREE IS NOT EMPTY\n\n";
  }
  if (bpt2.empty()) {
    cout << "SECOND TREE IS EMPTY\n\n";
  } else {
    cout << "SECOND TREE IS NOT EMPTY\n\n";
  }

  // test = operator
  cout << "\nSETTING SECOND TREE = FIRST TREE\n\n";
  bpt2 = bpt;

  cout << "FIRST TREE:\n\n";
  cout << bpt << endl << endl;
  bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
  cout << "SECOND TREE:\n\n";
  cout << bpt2 << endl << endl;
  bpt2.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";

  // now clear the first
  cout << "CLEARING FIRST TREE:\n\n";
  bpt.clear_tree();

  cout << "FIRST TREE:\n\n";
  cout << bpt << endl << endl;
  bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
  cout << "SECOND TREE:\n\n";
  cout << bpt2 << endl << endl;
  bpt2.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";

  // test empty
  if (bpt.empty()) {
    cout << "FIRST TREE IS EMPTY\n\n";
  } else {
    cout << "FIRST TREE IS NOT EMPTY\n\n";
  }
  if (bpt2.empty()) {
    cout << "SECOND TREE IS EMPTY\n\n";
  } else {
    cout << "SECOND TREE IS NOT EMPTY\n\n";
  }

  cout << "\n\n----------------END TEST---------------\n\n";
}

void contains_get_test() {
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tC O N T A I N S / G E T  T E S T\n";
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  // make a tree
  BPlusTree<int> bpt(true);

  // insert 0-99
  for (int i = 0; i < 100; ++i) {
    bpt.insert(i);
  }

  // lets display the tree
  cout << "Tree:\n\n" << bpt << endl << endl;

  // test contains on inserted values
  for (int i = 0; i < 100; ++i) {
    if (!bpt.contains(i)) {
      cout << "ERROR: " << i << " NOT FOUND\n\n";
    }
  }
  // verify tree
  bpt.is_valid() ? cout << "VERIFIED\n\n" : cout << "NOT VERIFIED\n\n";

  // get all the values in tree and print them
  cout << "Getting all values in the tree\n\n";
  for (int i = 0; i < 100; ++i) {
    cout << bpt.get(i) << endl;
  }
  // make sure the size is not changing (doesn't create a duplicate)
  cout << "SIZE : " << bpt.size() << endl << endl;

  // make sure get is inserting items that are not in tree
  cout << "Using get() on values 100-199\n\n";
  for (int i = 100; i < 200; ++i) {
    cout << bpt.get(i) << endl;
  }
  cout << "SIZE : " << bpt.size() << endl << endl;

  // insert duplicate items and check the size
  cout << "--Trying to insert 100 duplicates--\n\n";
  for (int i = 0; i < 100; ++i) {
    bpt.insert(i);
  }
  cout << "SIZE : " << bpt.size() << endl << endl;
  cout << "\n\n----------------END TEST---------------\n\n";
}

void iterator_search_test() {
  for (int i = 0; i < 54; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tI T E R A T O R  S E A R C H  T E S T\n";
  for (int i = 0; i < 54; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  // make our tree
  BPlusTree<int> bpt(true);
  // insert even values between 0-100
  for (int i = 0; i < 101; i = i + 2) {
    bpt.insert(i);
  }
  cout << "Tree:\n\n" << bpt << endl << endl;

  // create an iterator
  BPlusTree<int>::Iterator it;

  // test find() by searching for values
  cout << "--Looking for 42--\n\n";
  it = bpt.find(42);
  if (*it) {
    cout << "FOUND : [" << *it << "]\n\n";
  } else {
    cout << "NOT FOUND";
  }
  // test the iterator
  cout << "Testing the iterator:\n\n";
  for (int i = 0; i < 3; ++i) {
    cout << "iterator++\n";
    it++;
    it.print_Iterator();
    cout << endl;
  }
  cout << endl;

  // try a value that doesn't exist
  cout << "--Looking for 87--\n\n";
  it = bpt.find(87);
  if (!it.is_null()) {
    cout << "FOUND : [" << *it << "]\n\n";
  } else {
    cout << "NOT FOUND\n\n";
  }
  // try a different value
  cout << "--Looking for 96--\n\n";
  it = bpt.find(96);
  if (*it) {
    cout << "FOUND : [" << *it << "]\n\n";
  } else {
    cout << "NOT FOUND";
  }
  // test the iterator
  cout << "Testing the iterator:\n\n";
  cout << "iterator++\n";
  it++;
  if (!it.is_null()) {
    cout << *it << endl;
  } else {
    cout << "NULL\n";
  }
  cout << "iterator++\n";
  it++;
  if (!it.is_null()) {
    cout << *it << endl;
  } else {
    cout << "NULL\n";
  }
  cout << "iterator++\n";
  it++;
  if (!it.is_null()) {
    cout << *it << endl << endl;
  } else {
    cout << "NULL\n\n";
  }

  // lets clear tree to run different tests
  bpt.clear_tree();

  // insert duplicate values
  for (int i = 0; i < 30; ++i) {
    bpt.insert(i);
    bpt.insert(i);
    bpt.insert(i);
  }

  // display tree
  cout << "\nNew Tree For Bound Tests:\n\n" << bpt << endl << endl;

  // test lower bound for a few values
  it = bpt.lower_bound(1);
  if (!it.is_null()) {
    cout << "lower_bound(1) : " << *it << endl;
  } else {
    cout << "NULL\n\n";
  }
  // test iterator
  for (int i = 0; i < 3; ++i) {
    cout << "iterator++\n";
    it++;
    it.print_Iterator();
    cout << endl;
  }
  cout << endl;

  it = bpt.lower_bound(29);
  if (!it.is_null()) {
    cout << "lower_bound(29) : " << *it << endl;
  } else {
    cout << "NULL\n\n";
  }
  cout << endl;

  it = bpt.lower_bound(13);
  if (!it.is_null()) {
    cout << "lower_bound(13) : " << *it << endl;
  } else {
    cout << "NULL\n\n";
  }
  // test iterator
  for (int i = 0; i < 3; ++i) {
    cout << "iterator++\n";
    it++;
    it.print_Iterator();
    cout << endl;
  }
  cout << endl;

  // test upper bound
  it = bpt.upper_bound(5);
  if (!it.is_null()) {
    cout << "upper_bound(5) : " << *it << endl;
  } else {
    cout << "NULL\n\n";
  }
  // test iterator
  for (int i = 0; i < 3; ++i) {
    cout << "iterator++\n";
    it++;
    it.print_Iterator();
    cout << endl;
  }
  cout << endl;

  it = bpt.upper_bound(24);
  if (!it.is_null()) {
    cout << "upper_bound(24) : " << *it << endl;
  } else {
    cout << "NULL\n\n";
  }
  // test iterator
  for (int i = 0; i < 3; ++i) {
    cout << "iterator++\n";
    it++;
    it.print_Iterator();
    cout << endl;
  }
  cout << endl;

  it = bpt.upper_bound(13);
  if (!it.is_null()) {
    cout << "upper_bound(13) : " << *it << endl;
  } else {
    cout << "NULL\n\n";
  }
  // test iterator
  for (int i = 0; i < 3; ++i) {
    cout << "iterator++\n";
    it++;
    it.print_Iterator();
    cout << endl;
  }
  cout << endl;

  cout << "\n\n----------------END TEST---------------\n\n";
}

void removal_test1() {
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\t R E M O V A L  T E S T  1\n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;
  srand(time(0));
  // create a sample tree
  BPlusTree<int> bpt(true);
  for (int i = 0; i < 15; ++i) {
    bpt.insert(i);
  }
  // display initial tree
  cout << "Initial Tree:\n\n" << bpt << endl << endl;
  bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
  cout << "Size: " << bpt.size() << endl << endl;

  // remove each item
  for (int i = 0; i < 15; ++i) {
    cout << "--Removing " << i << "--\n\n";
    bpt.remove(i);
    cout << bpt << endl << endl;
    bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
    cout << "Size: " << bpt.size() << endl << endl;
  }

  cout << "\n\n----------------END TEST---------------\n\n";
}

void removal_test2() {
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\t R E M O V A L  T E S T  2\n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;
  srand(time(0));
  // create a sample tree
  BPlusTree<int> bpt(true);
  int size = 25;

  // make a shuffled array to insert and remove randomly
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = i;
  }
  shuffle(array, size);

  for (int i = 0; i < size; ++i) {
    bpt.insert(array[i]);
  }
  cout << "Making a new tree of size: " << size << "\n\n";
  cout << bpt << endl << endl;

  shuffle(array, size);

  for (int i = 0; i < size; ++i) {
    cout << "--Removing " << array[i] << endl << endl;
    bpt.remove(array[i]);
    cout << bpt << endl << endl;
    bpt.is_valid() ? cout << "VALID\n\n" : cout << "NOT VALID\n\n";
    cout << "Size: " << bpt.size() << endl << endl;
  }

  cout << "\n\n----------------END TEST---------------\n\n";
}

void mass_insertion_deletion_test() {
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\t MASS INSERTION AND DELETION TEST\n";
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl << endl;
  srand(time(0));
  // create a sample tree
  BPlusTree<int> bpt(true);

  int size = 500;
  // make a shuffled array to insert and remove randomly
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = i;
  }
  shuffle(array, size);

  // insert a lot of values while making sure tree is valid
  cout << "Making a new tree of size: " << size << "\n\n";

  int current_size = 0;
  for (int i = 0; i < size; ++i) {
    if (bpt.insert(array[i])) {
      current_size++;
    }
    bpt.is_valid();  // will assert if not valid
  }

  // re-shuffle array
  shuffle(array, size);

  cout << "Removing " << size << " elements one by one\n\n";
  //  remove all values while making sure tree is valid
  for (int i = 0; i < size; ++i) {
    if (bpt.remove(array[i])) {
      current_size--;
    }
    bpt.is_valid();  // will assert if not valid
    cout << "Size: " << bpt.size() << endl << endl;
  }

  cout << "Tests have been successful!" << endl;

  cout << "\n\n----------------END TEST---------------\n\n";
}

#endif  // BPT_TESTS_H_
