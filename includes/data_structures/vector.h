/*
 * Author: Christian Garcia
 * Project: Vector Class Implementation
 *
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <cassert>
#include <initializer_list>
#include <iomanip>
#include <iostream>

using namespace std;

template <typename T>
void vector_quick_sort(T a[], unsigned int size);
template <typename T>
void vector_Iswap(T &i1, T &i2);
template <typename T>
size_t vector_partition (T arr[], size_t size);

template <typename T>
class Vector {
 public:
  T push(T);              // returns item added
  T push_back(T);         // same as push
  T push(T, int);         // returns item added at index
  T get(int);             // returns item at index
  T pop();                // returns item removed
  T erase(int);           // erases item at index
  Vector<T> ignore(int);  // returns a vector without a certain index
  Vector<T> pick(
      Vector<int> indices);       // returns a vector containing these indices
  void clear();                   // empties the vector
  unsigned int size() const;      // returns size
  unsigned int capacity() const;  // returns capacity
  void print(ostream& outs = cout) const;  // displays items in vector
  unsigned int double_capacity();          // doubles capacity of vector
  const T& operator[](int index) const;    // returns arr[index]
  T& operator[](int index);
  Vector<T>& operator+=(const T& v2) {
    push(v2);
    return *this;
  }
  Vector<T>& operator+=(const Vector<T>& v2) {
    for (int i = 0; i < v2.size(); ++i) {
      push(v2[i]);
    }
    return *this;
  }

  Vector();                   // default constructor
  Vector(const Vector& src);  // copy constructor
  Vector(initializer_list<T> list);
  Vector(T array[], int size);
  ~Vector();  // destructor

  Vector& operator=(const Vector& src) {
    delete[] arr;
    // transfer variables
    _size = src._size;
    _capacity = src._capacity;
    // copy the array
    arr = new T[_capacity];
    for (int i = 0; i < _size; i++) {
      arr[i] = src.arr[i];
    }
    // return the copy
    return *this;
  }

  friend Vector<T> v_union(const Vector<T>& v1, const Vector<T>& v2) {
    int capacity = v1.size() + v2.size();
    T* arr3 = new T[capacity];
    int itr1 = 0, itr2 = 0, itr3 = 0;
    int size = 0;

    vector_quick_sort(v1.arr,v1.size());
    vector_quick_sort(v2.arr,v2.size());
  
    // while still moving through both arrays
    while (itr1 < v1._size && itr2 < v2.size()) {
      // put the lowest value into the new array
      if (v1.arr[itr1] < v2.arr[itr2]) {
        arr3[itr3++] = v1.arr[itr1++];
        size++;
      }  // don't allow duplicates
      else if (v1.arr[itr1] == v2.arr[itr2]) {
        arr3[itr3++] = v1.arr[itr1++];
        size++;
        itr2++;
      } else {
        arr3[itr3++] = v2.arr[itr2++];
        size++;
      }
    }
    // put remaining values into the new array
    while (itr1 < v1.size()) {
      arr3[itr3++] = v1.arr[itr1++];
      size++;
    }
    while (itr2 < v2.size()) {
      arr3[itr3++] = v2.arr[itr2++];
      size++;
    }
    return Vector<T>(arr3, size);
  }

  friend Vector<T> v_inter(const Vector<T>& v1, const Vector<T>& v2) {
    int capacity = v1.size() + v2.size();
    T* arr3 = new T[capacity];
    int itr1 = 0, itr2 = 0, itr3 = 0;
    int size = 0;

    vector_quick_sort(v1.arr,v1.size());
    vector_quick_sort(v2.arr,v2.size());

    // while still moving through both arrays
    while (itr1 < v1._size && itr2 < v2.size()) {
      // put the lowest value into the new array
      if (v1.arr[itr1] < v2.arr[itr2]) {
        itr1++;
      }  // only add same value
      else if (v1.arr[itr1] == v2.arr[itr2]) {
        arr3[itr3++] = v1.arr[itr1++];
        itr2++;
        size++;
      } else {
        itr2++;
      }
    }
    return Vector<T>(arr3, size);
  }

  friend ostream& operator<<(ostream& outs, const Vector& print_me) {
    print_me.print(outs);
    return outs;
  }

 private:
  T* arr;                  // pointer to store address of vector
  unsigned int _size;      // size of vector
  unsigned int _capacity;  // capacity of vector
};

template <typename T>  // default constructor
// sets size to 0, capacity to 1
Vector<T>::Vector() : _size(0), _capacity(1) {
  // allocates storage for vector
  arr = new T[_capacity];
}

template <typename T>  // copy constructor
Vector<T>::Vector(const Vector<T>& src) {
  // transfer variables
  _size = src._size;
  _capacity = src._capacity;
  arr = new T[_capacity];
  // copy the array
  for (int i = 0; i < _size; i++) {
    arr[i] = src.arr[i];
  }
}

template <typename T>
Vector<T>::Vector(initializer_list<T> list) {
  _size = 0;
  _capacity = list.size();
  arr = new T[_capacity];
  for (T element : list) {
    arr[_size] = element;
    _size++;
  }
}

template <typename T>
Vector<T>::Vector(T array[], int size) {
  _size = 0;
  _capacity = size;
  arr = new T[_capacity];
  for (int i = 0; i < size; ++i) {
    push(array[i]);
  }
}

template <typename T>  // destructor
Vector<T>::~Vector() {
  _size = 0;
  delete[] arr;
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
  assert(index < _size);
  return arr[index];
}

template <typename T>
T& Vector<T>::operator[](int index) {
  assert(index < _size);
  return arr[index];
}

template <typename T>  // inserts an item and returns the value
T Vector<T>::push(T item) {
  // change capacity if needed
  if (_size == _capacity) {
    double_capacity();
  }
  // insert data
  arr[_size] = item;
  _size++;
  return item;
}

template <typename T>  // inserts an item and returns the value
T Vector<T>::push_back(T item) {
  // change capacity if needed
  if (_size == _capacity) {
    double_capacity();
  }
  // insert data
  arr[_size] = item;
  _size++;
  return item;
}

template <typename T>  // inserts an item at index and returns the value
T Vector<T>::push(T item, int index) {
  assert(index < _capacity);  // index cannot be outside of the limit
  // use push if it achieves the same result
  if (index == _size) {
    return push(item);
  } else {
    // insert data
    arr[index] = item;
    return item;
  }
}

template <typename T>  // returns the item at an index
T Vector<T>::get(int index) {
  assert(index < _size);  // index cannot be outside the limit
  // return value if it is in the vector
  return arr[index];
}

template <typename T>  // returns the item removed
T Vector<T>::pop() {
  // item removed is at the end of the vector
  T removed = arr[_size - 1];
  _size--;
  return removed;
}

template <typename T>  // returns the item removed
T Vector<T>::erase(int index) {
  // item removed is at the end of the vector
  assert(index < _size);
  T removed = arr[index];
  _size--;
  for (int i = index; index < _size; ++i) {
    arr[i] = arr[i + 1];
  }
  return removed;
}

template <typename T>
Vector<T> Vector<T>::ignore(int index) {
  Vector<T> result;
  for (int i = 0; i < _size; ++i) {
    if (i != index) {
      result.push((*this)[i]);
    }
  }
  return result;
}

template <typename T>
Vector<T> Vector<T>::pick(Vector<int> indices) {
  Vector<T> result;
  for (int i = 0; i < indices.size(); ++i) {
    result.push((*this)[indices[i]]);
  }
  return result;
}

template <typename T>
void Vector<T>::clear() {
  _size = 0;
}

template <typename T>  // returns the size
unsigned int Vector<T>::size() const {
  return _size;
}

template <typename T>  // returns the capacity
unsigned int Vector<T>::capacity() const {
  return _capacity;
}

template <typename T>  // displays each item in the vector
void Vector<T>::print(ostream& outs) const {
  // loop through the vector
  for (int i = 0; i < _size; i++) {
    // display each item followed by a space
    // outs << left << setw(10) << arr[i];
    outs << arr[i] << " ";
  }
}

template <typename T>  // doubles the capacity
unsigned int Vector<T>::double_capacity() {
  // double capacity
  _capacity = _capacity * 2;
  // allocate space
  T* temp = new T[_capacity];
  // transfer info
  for (int i = 0; i < _size; i++) {
    temp[i] = arr[i];
  }
  // delete old vector
  delete[] arr;
  // set new vector
  arr = temp;
  // return new capacity
  return _capacity;
}

template <class T>
void vector_quick_sort(T a[], unsigned int size) {
  size_t pivot_index;
  size_t size1;  // elements before pivot
  size_t size2;  // elements after pivot
  // divide and reorganize the array using partition
  if (size > 1) {
    //partition(a, size, pivot_index);
    pivot_index = vector_partition(a, size);
    size1 = pivot_index;
    size2 = size - size1 - 1;
    // call function recursively on subarrays
    vector_quick_sort(a, size1);
    vector_quick_sort((a + pivot_index + 1), size2);
  }
}

// swaps two items
template <class T>
void vector_Iswap(T &i1, T &i2) {
  T temp = i1;
  i1 = i2;
  i2 = temp;
}

// used by quick_sort
template <class T>
size_t vector_partition (T arr[], size_t size) {
    // pivot which will be used to compare items
    T pivot = arr[0]; 
    // number of items smaller than pivot 
    size_t i = 0;

    for (int j = 1;j <= size-1; j++) {
        // swap item if smaller than pivot
        if (arr[j] < pivot) {
            vector_Iswap(arr[++i],arr[j]);
        }
    }
    //move pivot to its rightful place
    vector_Iswap(arr[i],arr[0]);
    return i;
}

#endif  // VECTOR_H_
