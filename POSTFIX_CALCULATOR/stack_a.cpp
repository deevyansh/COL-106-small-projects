#include <iostream>
#include<stdexcept>
using namespace std;
/* PART A */
/* Stacks using Fixed Size Arrays */

class Stack_A {
private:
    int stk[1024]; // The fixed size array
    int size; // Number of elements in the stack

public:
    // Constructor
    Stack_A();

    void push(int data);
    int pop();
    int get_element_from_top(int idx);
    int get_element_from_bottom(int idx);
    void print_stack(bool top_or_bottom);
    int add();
    int subtract();
    int multiply();
    int divide();
    int* get_stack();
    int get_size();


};

Stack_A::Stack_A(){
    size=0;
};

void Stack_A::push(int data){
    if (size>=1024){
        throw runtime_error("Stack Full");
    }
    else{
        stk[size]=data;
        size++;
    }
};

int Stack_A::pop(){
    if (size==0){
        throw runtime_error("Empty Stack");
    }
    else{
        size=size-1;
        //may be an error
        return (stk[size]);
    }
};

int Stack_A::get_element_from_top(int idx){
    if (idx<0 || idx>=size){
        throw runtime_error("Index out of range");
    }
    else{
        return (stk[size-idx-1]);}
};

int Stack_A::get_element_from_bottom(int idx){
    if (idx<0 || idx>=size){
        throw runtime_error("Index out of range");
    }
    else{
        return (stk[idx]);}
};

void Stack_A::print_stack(bool top_or_bottom){
    if (top_or_bottom ==0){
        for (int i=0; i<size; i++){
            cout<<stk[i];
            cout<<endl;
        }
    }
    else {
        for (int i=0; i<size; i++){
            cout<<stk[size-i-1];
            cout<<endl;
        }
    }
};

int Stack_A::add(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=pop();
    int b=pop();
    push(a+b);
    return (a+b);
}

int Stack_A::subtract(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=pop();
    int b=pop();
    push(b-a);
    return (b-a);
}

int Stack_A::multiply(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=pop();
    int b=pop();
    push(b*a);
    return (b*a);
}

int Stack_A::divide(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=pop();
    if (a==0){
        throw runtime_error("Divide by Zero Error");
    }
    int b=pop();
    int result =b/a;
    if ((b < 0 && a > 0) || (b > 0 && a < 0)) {
        result = (result * -1) - 1;
    }
    push(result);
    return (result);
};

int* Stack_A::get_stack(){
    int *arr =&stk[0];
    return (arr);
}; // Get a pointer to the array

int Stack_A::get_size(){
    return (size);
}; // Get the size of the stack