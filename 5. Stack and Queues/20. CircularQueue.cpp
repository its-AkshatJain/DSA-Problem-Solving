#include <iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        // To check if queue is full
        if((front==0 && rear==size-1) || (front!=0 && rear == (front-1)%(size-1) )){
            return false;
        }else if(front == -1){ // queue is empty/ inserting first element
            front = rear = 0;
        }else if(else if(rear == size-1 && front!=0)){ // to maintain cyclic nature
            rear = 0;
        }else{  // normal flow
            rear++;
        }
        // Push value inside queue
        arr[rear] = value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front == -1){ // queue is empty
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ // if single element is present
            front = rear = -1;
        }else if(front == size-1){ // to maintain cyclic nature
            front = 0;
        }else{  // normal flow
            front++;
        }
        return ans;
    }
};

int main(){
    CircularQueue q(8);
    q.enqueue(15);
    q.enqueue(5);
    q.enqueue(19);
    q.enqueue(8);

    cout<<"Popped element is : "<<q.dequeue()<<endl;
}