#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    private:
    Node* top;

    public:
    Stack(){
        top = NULL;
    }

    void push(int value){
        Node* newNode = new Node(value);

        // If newNode is not created due to lack of memeory
        if(!newNode){  //if(newnode == NULL)
            cout<<"Stack OverFlow!"<<endl;
        }else{
            newNode->next = top;
            top = newNode;
        }
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack UnderFlow!"<<endl;
        }else{
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek(){
        if(top!=NULL){
            return top->data;
        }else{
            return -1;
        }
    }

    bool empty(){
        if(top==NULL){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Stack s;
    s.push(45);
    s.push(89);
    s.push(73);

    s.pop();

    cout<<"Top element of stack is : "<<s.peek()<<endl;

    if(s.empty()){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"Stack is not Empty"<<endl;
    }

}