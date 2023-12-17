#include<iostream>

#include<stdexcept>
#include "node.h"
using namespace std;

/* PART B */
/* Stacks using Linked Lists */

/*
Linked Lists with Sentinels
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/

class List {
private:
    int size;
    Node* sentinel_head;
    Node* sentinel_tail;

public:
    List();
    void insert(int v);
    int delete_tail();
    int get_size();
    Node* get_head();
    Node* get_tail();
    ~List();
};
List::List(){
    size=0;
    sentinel_head= new Node (true);
    sentinel_tail= new Node (true);
    sentinel_tail->prev=sentinel_head;
    sentinel_head->next=sentinel_tail;
};

List::~List(){
    delete sentinel_tail;
    delete sentinel_head;
};

// Insert an element at the tail of the linked list
void List::insert(int v){
    Node *n2= new Node (v,sentinel_tail, sentinel_tail->prev);
    sentinel_tail->prev->next= n2;
    sentinel_tail->prev=n2;
    size++;
};

// Delete the tail of the linked list and return the value
// You need to delete the valid tail element, not the sentinel
int List::delete_tail(){
    sentinel_tail->prev->prev->next=sentinel_tail;
    int temp= (sentinel_tail->prev->get_value());
    sentinel_tail->prev=sentinel_tail->prev->prev;
    size--;
    return (temp);

};

// Return the size of the linked list
// Do not count the sentinel elements
int List::get_size(){
    return size;
};

// Return a pointer to the sentinel head of the linked list
Node* List::get_head(){
    return(sentinel_head);
};


