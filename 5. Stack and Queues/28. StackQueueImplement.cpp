#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// Implement Stack using Queue
class Stack{
    private:
    queue<int> q;

    public:
    void push(int data){
        int size = q.size();
        q.push(data);
        for(int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        if(!q.empty()){
            q.pop();
        }
    }

    int top(){
        if(!q.empty()){
            return q.front();
        }
        return -1;
    }

    bool empty(){
        if(q.empty()){
            return true;
        }
        return false;
    }

};


// Implement Queue using Stack
class Queue{
    private:
    stack<int> s1, s2;

    public:
    void enqueue(int data){
        s1.push(data);
    }

    void dequeue(){
        // Transfering element to empty stack 
        if(s2.empty()){
            while(!s1.empty()){
                int val = s1.top();
                s2.push(val);
                s1.pop();
            }
        }
        // deleting top elements of s2
        if(!s2.empty()){
            s2.pop();
        }
    }

    int front(){
        if(s2.empty()){
            while(!s1.empty()){
                int val = s1.top();
                s2.push(val);
                s1.pop();
            }
        }
        if(!s2.empty()){
            return s2.top();  // returning front 
        }
        return -1;
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }

    
};

int main(){
    Stack s;
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);

    s.pop();

    cout<<"Top of Stack is :"<<s.top()<<endl;
    cout<<"Stack is empty or not :"<<s.empty()<<endl;

    Queue q;

    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);

    q.dequeue();

    cout<<"Front of queue is :"<<q.front()<<endl;
    cout<<"Queue is empty or not :"<<q.empty()<<endl;

    return 0;
}