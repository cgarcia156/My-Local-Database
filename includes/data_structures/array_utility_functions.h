#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include "vector.h"

namespace cg {
template <class T>
T maximal(const T& a, const T& b);  // return the larger of the two items

template <class T>
void swap(T& a, T& b);  // swap the two items

template <class T>
int index_of_maximal(T data[],
                     int n);  // return index of the largest item in data

template <class T>
void ordered_insert(T data[], int& n, T entry);  // insert entry into the sorted
                                                 // array data with length n

template <class T>
int first_ge(const T data[], int n,
             const T& entry);  // return the first element in data that is
                               // not less than entry

template <class T>
void attach_item(T data[], int& n,
                 const T& entry);  // append entry to the right of data

template <class T>
void insert_item(T data[], int i, int& n,
                 T entry);  // insert entry at index i in data

template <class T>
void detach_item(T data[], int& n, T& entry);  // remove the last element in
                                               // data and place it in entry

template <class T>
void delete_item(T data[], int i, int& n,
                 T& entry);  // delete item at index i and place it in entry

template <class T>
void merge(T data1[], int& n1, T data2[],
           int& n2);  // append data2 to the right of data1

template <class T>
void split(T data1[], int& n1, T data2[],
           int& n2);  // move n/2 elements from the right of data1
                      // and move to data2

template <class T>
void copy_array(T dest[], const T src[], int& dest_size,
                int src_size);  // copy src[] into dest[]

template <class T>
void print_array(const T data[], int n, int pos = -1);  // print array data

template <class T>
bool is_gt(const T data[], int n, const T& item);  // item > all data[i]

template <class T>
bool is_le(const T data[], int n, const T& item);  // item <= all data[i]

//-------------- Vector Extra operators: ---------------------

template <typename T>
std::ostream& operator<<(std::ostream& outs,
                         const Vector<T>& list);  // print vector list

template <typename T>
Vector<T>& operator+=(Vector<T>& list,
                           const T& addme);  // list.push_back addme


// return the larger of the two items
template <class T>
T maximal(const T& a, const T& b) {
  return (a < b ? b : a);
}

// swap the two items
template <class T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

// return index of the largest item in data
template <class T>
int index_of_maximal(T data[], int n) {
  assert(n > 0);
  int max_index = 0;
  for (int i = 1; i < n; ++i) {
    if (data[i] > data[max_index]) {
      max_index = i;
    }
  }
  return max_index;
}

// insert entry into the sorted
// array data with length n
template <class T>
void ordered_insert(T data[], int& n, T entry) {
  int i = 0;
  i = first_ge(data, n, entry);
  for (int j = n; j > i; --j) {
    data[j] = data[j - 1];
  }
  data[i] = entry;
  n++;
}

// return the first element in data that is
// not less than entry
template <class T>
int first_ge(const T data[], int n, const T& entry) {
  int i;
  for (i = 0; (data[i] < entry) && (i < n); ++i) {
  }
  return i;
}

 // append entry to the right of data
template <class T>
void attach_item(T data[], int& n, const T& entry) {
  data[n] = entry;
  n++;
}

// insert entry at index i in data
template <class T>
void insert_item(T data[], int i, int& n, T entry) {
  for(int j=n;j>i;--j) {
    data[j] = data[j-1];
  }
  data[i] = entry;
  n++;
}

// remove the last element in
// data and place it in entry
template <class T>
void detach_item(T data[], int& n, T& entry) {
  entry = data[n-1];
  n--;
}

// delete item at index i and place it in entry
template <class T>
void delete_item(T data[], int i, int& n, T& entry) {
  entry = data[i];
  for(int j=i;j<n;++j) {
    data[j] = data[j+1];
  } 
  n--;
}

// append data2 to the right of data1
template <class T>
void merge(T data1[], int& n1, T data2[], int& n2) {
  for(int i=n1;i<n1+n2;++i) {
    data1[i] = data2[i-n1];
  }
  n1+=n2;
  n2 = 0;
}

// move n/2 elements from the right of data1
// and move to data2
template <class T>
void split(T data1[], int& n1, T data2[], int& n2) {
  T temp;
  int middle = n1/2;
  for(int i=0;i<middle;++i) {
    detach_item(data1,n1,temp);
    insert_item(data2,0,n2,temp);
  }
}

// copy src[] into dest[]
template <class T>
void copy_array(T dest[], const T src[], int& dest_size, int src_size) {
  for(int i=0;i<src_size;++i) {
    dest[i] = src[i];
  }
  dest_size = src_size;
}

// print array data
template <class T>
void print_array(const T data[], int n, int pos) {
  for(int i=0;i<n;++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
  if(pos>=0 && pos<n) {
    for(int i=0;i<pos;++i) {
      std::cout << "  ";
    }
    std::cout << "^";
  }
  std::cout << std::endl;
}

// item > all data[i]
template <class T>
bool is_gt(const T data[], int n, const T& item) {
  for(int i=0;i<n;++i) {
    if(item<=data[i]) {
      return false;
    }
  } return true;
}

// item <= all data[i]
template <class T>
bool is_le(const T data[], int n, const T& item) {
  for(int i=0;i<n;i++) {
    if(item>data[i]) {
      return false;
    }
  } return true;
}

// print vector list
template <typename T>
std::ostream& operator<<(std::ostream& outs,
                            const Vector<T>& list) {
  for(int i=0;i<list.size();++i) {
    outs << list[i] << " ";
  }
  return outs;
}

// list.push_back addme
template <typename T>
Vector<T>& operator+=(Vector<T>& list,
                           const T& addme) {
  list.push(addme);
  return list;
}


}  // namespace cg

#endif  // FUNCTIONS_H_
