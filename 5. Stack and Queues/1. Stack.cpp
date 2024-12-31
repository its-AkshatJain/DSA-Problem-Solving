#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public:
    // Stack properties
    int top;
    int *arr;
    int size;

    // Constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Stack Behaviour
    void push(int value){
        if(size - top > 1){
            top++;
            arr[top] = value;
        }else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }else{
            // Stack is empty
            cout<<"Stack UnderFlow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    bool empty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

};


int main(){
    // Creation of Stack Using STL
    stack<int> s;

    // Adding element to stack
    s.push(1);
    s.push(2);
    s.push(3);

    // Deleting Element from the stack
    s.pop();

    cout<<"Printing top of the Stack : "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"Stack is not Empty"<<endl;
    }

    // Creation of Stack Using Arrays in class
    Stack st(5);

    st.push(25);
    st.push(86);
    st.push(42);

    st.pop();

    cout<<"Top element of stack is : "<<st.peek()<<endl;

    if(st.empty()){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"Stack is not Empty"<<endl;
    }

}