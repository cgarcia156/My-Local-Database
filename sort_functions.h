#ifndef SORT_FUNCTIONS_H_
#define SORT_FUNCTIONS_H_

#include <iostream>
#include <random>
#include <string>
using namespace std;

//----------------SORT FUNCTIONS---------------------
template <class T>
void insertion_sort(T a[], unsigned int size);

template <class T>
void bubble_sort(T a[], unsigned int size);

template <class T>
void quick_sort(T a[], unsigned int size);

template <class T>
void merge_sort(T a[], unsigned int size);

template <class T>
void heap_sort(T a[], unsigned int size);

//---------------------------------------------------

// shuffle elements of a[]
template <class T>
void shuffle(T a[], unsigned int size);

// copy src[] to dest[]
template <class T>
void copy_array(T dest[], const T src[], unsigned int size);

// return true if a[] is in ascending order
template <class T>
bool verify(const T a[], unsigned int size);

// return a string "SORTED" or "NOT SORTED" depending if a[] is sorted
template <class T>
string verifystr(const T a[], unsigned int size);

// print the array if status_only is true along with info on sortedness of a[]
template <class T>
void print_array(const T a[], int size, bool status_only = false);

// print a[] from start to end
template <class T>
void print_array_segment(T a[], unsigned int start, unsigned int end);

// swap two items
template <class T>
void Iswap(T &i1, T &i2);

// used by quick_sort
template <class T>
size_t partition (T arr[], size_t size);

// helper function to combine subarrays
template <class T>
void merge(T *arr, size_t size1, size_t size2);

// makes a heap from an array
template <class T>
void make_heap(T data[], size_t size);

//--------OTHER HELPER FUNCTIONS FOR HEAPSORT---------

template <class T>
void reheapify_down(T data[], size_t size);

template <class T>
size_t big_child_index(T heap[], size_t i, size_t size);

size_t parent(size_t k);

bool is_leaflet(size_t i, size_t size);

size_t left_child_index(size_t i);

size_t right_child_index(size_t i);

//----------------------------------------------------------------------------

template <class T>
void insertion_sort(T a[], unsigned int size) {
  // for each element in the array
  for (int i = 1; i < size; i++) {
    // hold value
    T temp = a[i];
    int j = i - 1;
    // move up elements while value is smaller
    while ((temp < a[j]) && (j >= 0)) {
      a[j + 1] = a[j];
      j--;
    }
    // put value in its rightful place
    a[j + 1] = temp;
  }
}

template <class T>
void bubble_sort(T a[], unsigned int size) {
  // while array is not sorted
  while (!verify(a, size)) {
    // loop through array
    for (int i = 0; i < size - 1; ++i) {
      // swap if index is greater than next
      if (a[i] > a[i + 1]) {
        Iswap(a[i], a[i + 1]);
      }
    }
   size = size-1;
  }
}

template <class T>
void quick_sort(T a[], unsigned int size) {
  size_t pivot_index;
  size_t size1;  // elements before pivot
  size_t size2;  // elements after pivot
  // divide and reorganize the array using partition
  if (size > 1) {
    //partition(a, size, pivot_index);
    pivot_index = partition(a, size);
    size1 = pivot_index;
    size2 = size - size1 - 1;
    // call function recursively on subarrays
    quick_sort(a, size1);
    quick_sort((a + pivot_index + 1), size2);
  }
}

template <class T>
void merge_sort(T a[], unsigned int size) {
  size_t size1;  // size of first subarray
  size_t size2;  // size of second subarray

  if (size > 1) {
    // find sizes of two halves of the array
    size1 = size / 2;
    size2 = size - size1;

    // recursively call merge sort on subarrays
    merge_sort(a, size1);
    merge_sort((a + size1), size2);

    // merge the two halves
    merge(a, size1, size2);
  }
}

template <class T>
void heap_sort(T a[], unsigned int size) {
  size_t unsorted;
  
  //turn the array into a heap
  make_heap(a, size);

  unsorted = size;
  //move largest item to the back and reorganize heap
  while (unsorted > 1) {
    --unsorted;
    Iswap(a[0], a[unsorted]);
    reheapify_down(a, unsorted);
  }
}

// shuffle elements of a[]
template <class T>
void shuffle(T a[], unsigned int size) {
  for (int i = 0; i < size*3; i++) {
    size_t index1 = rand() % size;
    size_t index2 = rand() % size;
    Iswap(a[index1], a[index2]);
  }
}

// copy src[] to dest[]
template <class T>
void copy_array(T dest[], const T src[], unsigned int size) {
  // loop through src while copying to dest
  for (int i = 0; i < size; i++) {
    dest[i] = src[i];
  }
}

// returns true if a[] is in ascending order
template <class T>
bool verify(const T a[], unsigned int size) {
  // loop through array
  for (int i = 0; i < size - 1; i++) {
    // if an element is out of place return false
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}

// returns a string "SORTED" or "NOT SORTED"
template <class T>
string verifystr(const T a[], unsigned int size) {
  // use verify to check if sorted
  if (verify(a, size)) {
    return "SORTED";
  } else {
    return "NOT SORTED";
  }
}

// print array along with status unless status only is true
template <class T>
void print_array(const T a[], int size, bool status_only) {
  // if status only is false
  if (!status_only) {
    // loop through array while printing elements
    for (int i = 0; i < size; i++) {
      cout << a[i] << " ";
    }
  }
  // display status of a[]
  cout << verifystr(a, size) << endl;
}

// print a[] from start to end
template <class T>
void print_array_segment(T a[], unsigned int start, unsigned int end) {
  for (int i = start; i < end; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// swaps two items
template <class T>
void Iswap(T &i1, T &i2) {
  T temp = i1;
  i1 = i2;
  i2 = temp;
}

// used by quick_sort
template <class T>
size_t partition (T arr[], size_t size) {
    // pivot which will be used to compare items
    T pivot = arr[0]; 
    // number of items smaller than pivot 
    size_t i = 0;

    for (int j = 1;j <= size-1; j++) {
        // swap item if smaller than pivot
        if (arr[j] < pivot) {
            Iswap(arr[++i],arr[j]);
        }
    }
    //move pivot to its rightful place
    Iswap(arr[i],arr[0]);
    return i;
}

template <class T>  // helper function to combine subarrays
void merge(T *arr, size_t size1, size_t size2) {
  T *temp;
  // Number of total elements copied
  size_t copied = 0;
  // Number of elements copied from each subarray
  size_t copied1 = 0;
  size_t copied2 = 0;

  temp = new T[size1 + size2];

  // while still moving through both arrays
  while ((copied1 < size1) && (copied2 < size2)) {
    // put the lowest value into the new array
    if (arr[copied1] < (arr + size1)[copied2]) {
      temp[copied++] = arr[copied1++];
    } else {
      temp[copied++] = (arr + size1)[copied2++];
    }
  }
  // put remaining values into the new array
  while (copied1 < size1) {
    temp[copied++] = arr[copied1++];
  }
  while (copied2 < size2) {
    temp[copied++] = (arr + size1)[copied2++];
  }
  // copy data back into arr
  for (int i = 0; i < size1 + size2; i++) {
    arr[i] = temp[i];
  }
  delete[] temp;
}

//makes a heap from an array
template <class T>
void make_heap(T data[], size_t size) {
  size_t k;
  for (int i = 1; i < size; i++) {
    k = i;
    while (data[k] > data[parent(k)] && (k != 0)) {
      Iswap(data[k], data[parent(k)]);
      k = parent(k);
    }
  }
}

//helper function for heapsort, reorganizes heap
template <class T>
void reheapify_down(T data[], size_t size) {
  size_t current;
  size_t big_child;
  bool heap_ok;

  current = 0;
  heap_ok = false;
  
  //swap with child while child is larger
  while ((!heap_ok) && (!is_leaflet(current, size))) {
    big_child = big_child_index(data, current, size);

    if (data[current] < data[big_child]) {
      Iswap(data[current], data[big_child]);
      current = big_child;
    } else {
      heap_ok = true;
    }
  }
}

// returns parent index
inline size_t parent(size_t k) { return ((k - 1) / 2); }

// returns true if index has no children
bool is_leaflet(size_t i, size_t size) {
  bool isLeaf;
  if (left_child_index(i) >= size) {
    isLeaf = true;
  } else {
    isLeaf = false;
  }
  return isLeaf;
}

// returns index of left child
inline size_t left_child_index(size_t i) { return ((2 * i) + 1); }

// returns index of right child
inline size_t right_child_index(size_t i) { return ((2 * i) + 2); }

// returns index of biggest child
template <class T>
size_t big_child_index(T heap[], size_t i, size_t size) {
  size_t bigChild, leftChild, rightChild;
  if(right_child_index(i)>=size) {
    return left_child_index(i);
  }
  leftChild = left_child_index(i);
  rightChild = right_child_index(i);
  bigChild = (heap[leftChild] > heap[rightChild] ? leftChild : rightChild);
  return bigChild;
}
#endif  // SORT_FUNCTIONS_H_
