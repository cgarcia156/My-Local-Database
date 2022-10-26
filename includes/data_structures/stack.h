#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "list.h"
using namespace std;

template <class T>
class Stack{
public:
    Stack():_top(NULL){}

    ~Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator =(const Stack<T>& rhs);

    void push(T item);
    T pop();
    T top();
    bool empty();
    friend ostream& operator << (ostream& outs, const Stack& s){
        return print_list(s._top, outs);
    }
private:
    node<T>* _top;
};

//deconstructor deletes the stack
template <typename T>
Stack<T>::~Stack() {
    delete_all(_top);
}

//creates a stack by copying a stack
template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
    init_head(_top);
    copy_list(other._top,_top);
}

//copies one stack to another
template <typename T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rhs) {
    copy_list(rhs._top,_top);
    return *this;
}

//inserts a node* at the top of the stack
template <typename T>
void Stack<T>::push(T item) {
    insert_head(_top,item);
}

//removes a node* from the top of the stack
template <typename T>
T Stack<T>::pop() {
    //cout << "{ " << top() << " } ";
    return delete_head(_top);
}

//returns the item at the top of the stack
template <typename T>
T Stack<T>::top() {
    return _top->_item;
}

//returns True if stack is NULL
template <typename T>
bool Stack<T>::empty() {
    return isEmpty(_top);
}


#endif  // STACK_H_

