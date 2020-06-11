#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "../../!includes/functions/list.h"

using namespace std;

template <class T>
class Queue{
public:
    Queue():_head(NULL), _tail(NULL), _count(0){}

    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T> &operator =(const Queue& rhs);

    void push(T item);
    T pop();
    bool empty();
    T front();
    int size();

    friend ostream& operator <<(ostream& outs, const Queue& q){
        return print_list(q._head, outs);
    }

private:
    node<T>* _head;
    node<T>* _tail;
    int _count;
};

//deletes the queue
template <typename T>
Queue<T>::~Queue() {
    _tail = NULL;
    delete_all(_head);
}

//creates a queue by copying a queue
template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
    init_head(_head);
    _count = other._count;
    _tail = copy_list(other._head,_head);
}

//pushes a node* in the back of the queue
template <typename T>
void Queue<T>::push(T item) {
    _count++;
    if(empty()) {
        _head=_tail=insert_head(_head,item);
    } else {
        _tail=insert_after(_head,_tail,item);
    }
}

//removes the node* at the front of the queue
template <typename T>
T Queue<T>::pop() {
    assert(!empty());
    _count--;
    if(_head==_tail) {
        _tail = NULL;
    }
    return delete_head(_head);
}

//returns true if queue is empty
template <typename T>
bool Queue<T>::empty() {
    return isEmpty(_head);
}

//returns the item at the front of the queue
template <typename T>
T Queue<T>::front() {
    return _head->_item;
}

//copies one queue to another
template <typename T>
Queue<T> & Queue<T>::operator =(const Queue& rhs) {
    _tail = copy_list(rhs._head,_head);
    _count = rhs._count;
    return *this;
}

template <typename T>
int Queue<T>::size() {
    return _count;
}

#endif  // QUEUE_H_

