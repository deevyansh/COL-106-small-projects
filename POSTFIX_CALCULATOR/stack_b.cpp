#include <iostream>
#include<stdexcept>

using namespace std;

class Stack_B {
private:
    int* stk; // The dynamic array
    int size; // Number of elements in the stack
    int capacity; // Capacity of the stack

public:
    // Constructor
    Stack_B();
    ~Stack_B();
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

Stack_B::Stack_B(){
    capacity=1024;
    stk=new int [capacity];
    size=0;

};

// Destructor
Stack_B::~Stack_B(){
    delete[] stk;
};

void Stack_B::push(int data){
    if (size==capacity){
        capacity=capacity*2;
        int *temp =new int [capacity *2];
        for (int i=0; i<size; i++){
            temp[i]=stk[i];
        }
        delete [] stk;
        stk=temp;
    }
    stk[size]=data;
    size++;
};
int Stack_B::pop(){
    if (size==0){
        throw runtime_error("Empty Stack");
    }
    if (size==capacity/4){
        capacity=capacity/2;
        int *temp=new int [capacity];
        for (int i=0; i<size; i++){
            temp[i]=stk[i];
        }
        stk=temp;
        int t=(stk[size-1]);
        size=size-1;
        return (t);

    }
    else{
        int t=(stk[size-1]);
        size=size-1;
        return (t);}
};


//int Stack_B::pop() {
//    if (size == 0) {
//        throw runtime_error("Empty Stack");
//    }
//    size--;
//    if (capacity>1024){
//        if (capacity/4==size){
//            capacity=capacity/2;
//            int *temp =new int [capacity /2];
//            for (int i=0; i<size; i++){
//                temp[i]=stk[i];
//            }
//            stk=temp;
//        }
//    }
//    return stk[size];
//}


int Stack_B::get_element_from_top(int idx){
    if (idx<0 || idx>=size){
        throw runtime_error("Index out of range");
    }
    else{
        return (stk[size-idx-1]);}
};

int Stack_B::get_element_from_bottom(int idx){
    if (idx<0 || idx>=size){
        throw runtime_error("Index out of range");
    }
    else{
        return (stk[idx]);}
};

void Stack_B::print_stack(bool top_or_bottom){
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

int Stack_B::add(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=pop();
    int b=pop();
    push(a+b);
    return (a+b);
}

int Stack_B::subtract(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=pop();
    int b=pop();
    push(b-a);
    return (b-a);
}

int Stack_B::multiply(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int a=pop();
    int b=pop();
    push(b*a);
    return (b*a);
}

int Stack_B::divide(){
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
        if (b%a!=0){
            result = (result * -1) - 1;}
    }
    push(result);
    return (result);
};

int* Stack_B::get_stack(){
    int *arr =&stk[0];
    return (arr);
}; // Get a pointer to the array

int Stack_B::get_size(){
    return (size);
};






