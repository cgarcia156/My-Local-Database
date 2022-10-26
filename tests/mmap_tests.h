#ifndef M_MAP_TESTS_H_
#define M_MAP_TESTS_H_

#include <iostream>
#include "mmap.h"
#include "mpair.h"
#include "../../Sort Functions/!includes/sort_functions.h"

void mmap_test() {
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tM U L T I  M A P  T E S T \n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  MMap<int, std::string> mMap;
  mMap.insert(5, "Five");
  mMap.insert(9, "Nine");
  mMap.insert(4, "Four");
  mMap.insert(1, "One");
  mMap.insert(3, "Three");
  mMap.insert(8, "Eight");
  mMap.insert(2, "Two");
  mMap.insert(0, "Zero");
  mMap.insert(6, "Six");
  mMap.insert(7, "Seven");

  cout << "Initial Map:\n";
  cout << mMap << endl;

  cout << "inserting 8 alsoEight" << endl;
  mMap.insert(8, "alsoEight");
  cout << mMap << endl;

  cout << "inserting 2 Too" << endl;
  mMap.insert(2, "Too");
  cout << mMap << endl;

  cout << "--Erasing 3--\n\n";
  mMap.erase(3);
  cout << mMap << endl;

  cout << "myMap[0] : ";
  cout << mMap[0] << endl << endl;

  cout << "myMap.contains(3) : ";
  cout << mMap.contains(3) << endl << endl;
  cout << "myMap.contains(3) : ";
  cout << mMap.contains(3) << endl << endl;
  
  cout << "myMap.get(8) : ";
  cout << mMap.get(8) << endl << endl;

  // testing find() (returns an iterator)
  cout << "--Finding 5--\n\n";
  MMap<int, std::string>::Iterator it;
  it = mMap.find(5);
  cout << *it << endl << endl;
  cout << "It++\n\n";
  it++;
  cout << *it << endl << endl;
  cout << "It++\n\n";
  it++;
  cout << *it << endl << endl;
  cout << "It++\n\n";
  it++;
  cout << *it << endl << endl;
  cout << "It++\n\n";
  it++;
  cout << *it << endl << endl;

  mMap[18]+="18";
  mMap[12]+="twelve";

  mMap.erase(6);
  mMap.erase(4);
  mMap.erase(8);
  mMap.erase(5);
  mMap.erase(2);

  it = mMap.lower_bound(18);
  if(!it.is_null())
  cout << "lower_bound of 18: " << *it << endl;

  it = mMap.upper_bound(17);
  if(!it.is_null())
  cout << "upper_bound of 17: " << *it << endl;

  // Final Display of mMap
  MMap<int, std::string> mmap2 = mMap;
  cout << "map2:";
  cout << endl << mmap2 << endl;

  it = mmap2.begin();
  while(it!=mmap2.end()) {
    cout << *it << endl;
    it++;
  }

  cout << "\n\n----------------END TEST---------------\n\n";
}

void mmap_interactive_test() {
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tM-M A P  I N T E R A C T I V E  T E S T \n";
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  MMap<string, int> myMap;

  char input;
  // show the options to the user
  cout << "[I]nsert [C]lear [S]earch [R]emove [E]xists e[X]it: " << endl;
  cin >> input;
  // while user doesn't exit (x or X)
  while (input != 'x' && input != 'X') {
    switch (input) {
      // insert a certain number
      case 'I':
      case 'i': {
        cout << "Enter key(string) and value(int):\n";
        string key;
        cin >> key;
        int value;
        cin >> value;
        myMap.insert(key, value);
        cout << "-- Inserting " << key << ":" << value << endl;
        break;
      }
      // clear the tree
      case 'C':
      case 'c':
        myMap.clear();
        break;
      case 'R':
      case 'r': {
        string key;
        cout << "? ";
        cin >> key;
        bool found = myMap.erase(key);
        if (found) {
          cout << "[" << key << "] has been DELETED\n";
        } else {
          cout << "[" << key << "] DOES NOT EXIST\n";
        }
        break;
      }
      // search for an item
      case 'S':
      case 's': {
        string key;
        cout << "? ";
        cin >> key;
        bool found = myMap.contains(key);
        if (found) {
          cout << "[" << key << "] = " << myMap[key]<< endl;
        } else {
          cout << "[" << key << "] DOES NOT EXIST\n";
        }
        break;
      }
      case 'E':
      case 'e': {
        string key;
        cout << "? ";
        cin >> key;
        bool found = myMap.contains(key);
        if (found) {
          cout << "[" << key << "] EXISTS\n";
        } else {
          cout << "[" << key << "] DOES NOT EXIST\n";
        }
        break;
      }
      // show error for any other input
      default:
        cout << "Invalid Input" << endl << endl;
    }
    cout << endl << myMap << endl;
    cout << "size: " << myMap.size() << endl << endl;
    for (int i = 0; i < 25; i++) {
      cout << "=";
    }
    cout << endl;
    cout << "[I]nsert [C]lear [S]earch [R]emove [E]xists e[X]it: " << endl;
    cin >> input;
  }
  for (int i = 0; i < 25; i++) {
    cout << "=";
  }
  cout << "\n\n----------------END TEST---------------\n\n";
}

  void mass_mmap_test() {
 for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tM A S S  M M A P  T E S T \n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  MMap<int, int> myMap;
  int size = 500;
  for(int i=0;i<size;++i) {
    myMap.insert(i,rand());
    myMap.insert(i,rand());
  }
  
  cout << myMap << endl;

  int arr[size];
  for(int i=0;i<size;++i) {
    arr[i] = i;
  }

  shuffle(arr,size);

  for(int i=0;i<size;++i) {
    myMap.erase(arr[i]);
    cout << "Erasing : " << arr[i] << endl << endl;
    cout << myMap << endl << endl;
  }

  cout << "\n\n----------------END TEST---------------\n\n";
}

#endif  // M_MAP_TESTS_H_