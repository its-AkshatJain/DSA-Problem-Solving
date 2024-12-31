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

class Queue{
    Node* front;
    Node* rear;

    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);

        if(!newNode){
            cout<<"OverFlow Condition "<<endl;
        }
        if(rear == NULL){
            front = newNode;
            rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop(){
        // If ll is empty
        if(front == NULL){
            return -1;
        }else{
            Node* temp = front;
            front = front->next;

            // If the queue is empty after pop
            if(front == NULL){
                rear = NULL;
            }

            int poppedData = temp->data;
            delete temp;
            return poppedData;
        }
    }

    int qfront(){
        if(front == NULL){
            return -1;
        }else{
            return front->data;
        }
    }

    bool empty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.push(15);
    q.push(5);
    q.push(19);
    q.push(8);

    cout<<"Front of queue is : "<<q.qfront()<<endl;
    
    cout<<"Popped element is : "<<q.pop()<<endl;

    cout<<"Front of queue is : "<<q.qfront()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
}