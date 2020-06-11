#ifndef LIST_H_
#define LIST_H_

#include <cassert>
#include <iostream>
using namespace std;

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(const T& item = T(), node<T>* next = NULL):_item(item), _next(next){}
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head);

//deletes all the nodes in the list
template<class T>
void delete_all(node<T>*&head);

//true if head is NULL, false otherwise.
template <class T>
bool isEmpty(const node<T>* head);

//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy);

//insert at the beginning of the list:
template <class T>
node<T>* insert_head(node<T>* &head, T item);

//insert_after: if after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item);

//delete the node at the head of the list, return the item:
template <class T>
T delete_head(node<T>* &head);


template <class T>
node<T>* init_head(node<T>* &head) {
    //set head to NULL and return it
    head = NULL;
    return head;
}

template<class T>
void delete_all(node<T>*&head) {
    //assert if head is null
    /*
    if(head==NULL) {
      cout << "Warning: deleting nothing\n";
    }
    */
    //create a node pointer to iterate through the list
    node<T>* p = head;
    while (p!=NULL) {
      delete head;
      //set next node as the new head
      head = p->_next;
      //move to next node in the list
      p = p->_next;
    }
}

template <class T>
bool isEmpty(const node<T>* head) {
    //return true if head is NULL
    return (head == NULL);
}

template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy) {
    //assert if head is NULL
    assert(head!=NULL && "head pointer cannot be null");
    //delete cpy if it is not empty
    if (!isEmpty(cpy)) {
    delete_all(cpy);
    }
    //create a temp node* and set it equal to cpy
    node<T>* temp = cpy;
    //create a node* to iterate through the list
    const node<T>* p = head;
    //loop while the iterator is not null
    while (!isEmpty(p)) {
        //insert a node* with the original list's item
        //into the copied list
        temp = insert_after(cpy,temp,p->_item);
        //move to next node* in the list
        p = p->_next;
    }
    //return the tail of the list
    return temp;

}

template <class T>
node<T>* insert_head(node<T>* &head, T item) {
    //create a new node* which will be inserted
    node<T>* temp = new node<T>(item);
    //if head is null make temp the head
    if (!head) {
        head = temp;
        return temp;
    }
    //point temp to old head
    temp->_next = head;
    //set new head to temp
    head = temp;
    //return the inserted node*
    return temp;
}

template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item) {
    //create a new node* which will be inserted
    node<T>* temp = new node<T>(item);
    //create an iterator to move through the list
    node<T>* p = head;
    //if head is empty make temp the new head
    if (!head) {
        head = temp;
        //return the inserted node*
        return temp;
    }
    //if after is empty
    if(!after) {
        //point the new node*(temp) to head
        temp->_next = head;
        //make temp the new head
        head = temp;
        //return the inserted node*
        return head;
    }
    //loop until p is the node* we are looking for
    while (p != after) {
        assert(p!=NULL && "node is not in the list");
        p = p->_next;
    }
    //temp points to next node
    temp->_next = p->_next;
    //point current node to temp
    p->_next = temp;
    //return new node
    return temp;
}

template <class T>
T delete_head(node<T>* &head) {
    assert(head!=NULL && "head pointer cannot be null");
    //create a node* to hold the head
    node<T>* hold = head;
    //grab the head's item
    T item = head->_item;
    //move the head to the next node* in the list
    head = head->_next;
    //delete the node* holding the old head
    delete hold;
    //return the deleted head's item
    return item;
}

//print the list and return outs
template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout) {
    //loop while node* is not null
    while (head) {
        //uses operator overloading to display node*
        outs << *head;
        //moves to next node*
        head = head->_next;
    }
    outs << "|||";
    return outs;
}

#endif  // LIST_H_