#ifndef MAP_TESTS_H_
#define MAP_TESTS_H_

#include <iostream>

#include "../includes/data_structures/B+Tree.h"
#include "../includes/data_structures/map.h"
#include "../includes/sort_functions.h"


void map_test() {
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tS I M P L E  M A P  T E S T \n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  Map<int, string> myMap;
  myMap.insert(5, "Five");
  myMap.insert(9, "Nine");
  myMap.insert(4, "Four");
  myMap.insert(1, "One");
  myMap.insert(3, "Three");
  myMap.insert(8, "Eight");
  myMap.insert(2, "Two");
  myMap.insert(0, "Zero");
  myMap.insert(6, "Six");
  myMap.insert(7, "Seven");

  cout << myMap << endl;

  cout << "--Erasing 3--\n\n";
  myMap.erase(3);

  cout << myMap << endl;

  cout << "myMap[0] : ";
  cout << myMap[0] << endl << endl;

  cout << "myMap[4] = \"Five\"\n";
  cout << "myMap[4] : ";
  myMap[4] = "Five";
  cout << myMap[4] << endl << endl;

  cout << "myMap.contains(3) : ";
  cout << myMap.contains(3) << endl << endl;

  cout << "myMap.get(8) = NotEight\n";
  myMap.get(8) = "NotEight";
  cout << "myMap.get(8) : ";
  cout << myMap.get(8) << endl << endl;

  cout << "myMap.at(8) : ";
  cout << myMap.at(8) << endl << endl;

  cout << myMap << endl;

  Map<int,string>::Iterator it;
  for(it=myMap.begin();it!=myMap.end();++it) {
    cout << *it << endl;
  } cout << endl;

  cout << "--Finding 2--\n\n";
  it = myMap.find(2);
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

  Map<int,string> newMap(myMap);
  cout << "copied map: " << endl << newMap << endl;
  it = newMap.begin();
  while (it!=newMap.end()) {
    cout << *it << endl;
    it++;
  }

  cout << "\n\n----------------END TEST---------------\n\n";
}

void map_interactive_test() {
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tM A P  I N T E R A C T I V E  T E S T \n";
  for (int i = 0; i < 50; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  Map<string, int> myMap;

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

void mass_map_test() {
 for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl;
  cout << "\tM A S S  M A P  T E S T \n";
  for (int i = 0; i < 45; ++i) {
    cout << "-";
  }
  cout << endl << endl;

  Map<int, int> myMap;
  int size = 500;
  for(int i=0;i<size;++i) {
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

#endif  // MAP_TESTS_H_
