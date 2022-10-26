#ifndef FINAL_BPT_TEST_H_
#define FINAL_BPT_TEST_H_

#include "B+Tree.h"
#include "../../Sort Functions/!includes/sort_functions.h"

void final_remove_test() {
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\t FINAL REMOVE TEST\n";
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl << endl;
  srand(time(0));
  // create a sample tree
  BPlusTree<int> bpt(true);

  int size = 200;
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
    cout << "Removing:" << array[i] << endl << endl;
    if (bpt.remove(array[i])) {
      current_size--;
    }
    bpt.is_valid();  // will assert if not valid
    cout << bpt << endl << endl;
  }

  cout << "Tests have been successful!" << endl;

  cout << "\n\n----------------END TEST---------------\n\n";
}

#endif  // FINAL_BPT_TEST_H_
