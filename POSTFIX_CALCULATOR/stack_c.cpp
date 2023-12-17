#include<iostream>

using namespace std;
#include <string>
#include <stdexcept>

#include "node.h"
#include "list.h"



class Stack_C {
private:
    List* stk; // The linked list

public:
    // Constructor
    Stack_C();
    ~Stack_C();
    void push(int data);
    int pop();
    int get_element_from_top(int idx);
    int get_element_from_bottom(int idx);
    void print_stack(bool top_or_bottom);
    int add();
    int subtract();
    int multiply();
    int divide();
    List* get_stack();
    int get_size();

};
Stack_C::Stack_C(){
    stk = new List;
};

// Destructor
Stack_C::~Stack_C(){
    delete stk;
};

void Stack_C::push(int data){
    stk->insert(data);
};

int Stack_C::pop() {
    if (stk->get_size()==0){
        throw runtime_error("Empty Stack");
    }
    else{
        return (stk->delete_tail());
    }
};

int Stack_C::get_element_from_top(int idx){
    if (idx<0 || idx>=stk->get_size()){
        throw runtime_error("Index out of range");
    }
    Node *n;
    n=stk->get_head()->next;
    for (int i=0; i<((stk->get_size())-idx-1); i++){
        n=n->next;
    }
    return(n->get_value());

} ;

int Stack_C::get_element_from_bottom(int idx){
    if (idx<0 || idx>=stk->get_size()){
        throw runtime_error("Index out of range");
    }
    Node *n;
    n=stk->get_head()->next;
    for (int i=0; i<idx; i++){
        n=n->next;
    }
    return(n->get_value());
};

void Stack_C::print_stack(bool top_or_bottom){
    if (top_or_bottom==0){
        Node *n;
        n=stk->get_head()->next;
        for (int i=0; i<stk->get_size(); i++){
            cout<<n->get_value();
            n=n->next;
            cout<<endl;
        }}
    else{
        Node *n = stk->get_head();
        for (int i = 0; i < stk->get_size(); i++) {
            n = n->next;
        }
        for (int i = 0; i < stk->get_size(); i++) {
            cout << n->get_value() << endl;
            n = n->prev;
        }
    }
};

int Stack_C::add(){
    if (stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    stk->insert(a+b);
    return(a+b);
};

int Stack_C::subtract(){
    if (stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    stk->insert(b-a);
    return(b-a);
};

int Stack_C::multiply(){
    if (stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    stk->insert(a*b);
    return(a*b);

};

int Stack_C::divide(){
    if (stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    if (a==0){
        throw runtime_error("Divide by Zero Error");
    }
    int result =b/a;
    if ((b < 0 && a > 0) || (b > 0 && a < 0)) {
        result = (result * -1) - 1;
    }
    stk->insert(result);
    return(result);
};

List* Stack_C::get_stack(){
    return(stk);
}; // Get a pointer to the linked list representing the stack
int Stack_C::get_size(){
    return (stk->get_size());
}; // Get the size of the stack


















