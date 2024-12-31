#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int size;
    int front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // If queue is full
        if(isFull()){
            return false;
        }else if (isEmpty()) { // queue is empty/ inserting first element
            front = rear = 0;
        }else if(front == 0 && rear!= size-1){   // maintain cyclic flow
            front = size-1;
        }else{   // normal flow
            front--;
        }
        arr[front] = x;

        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // If queue is full
        if(isFull()){
            return false;
        }else if (isEmpty()) { // queue is empty/ inserting first element
            front = rear = 0;
        }else if(rear == size-1 && front!=0){   // maintain cyclic flow
            rear = 0;
        }else{   // normal flow
            rear++;
        }
        arr[rear] = x;

        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear){ // if single element is present
            front = rear = -1;
        }else if(rear == 0){ // to maintain cyclic nature
            rear = size-1;
        }else{  // normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1){
            return true;
        }else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) ||
            (front!=0 && rear == (front - 1) % (size - 1))) {
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Deque d(10);

    cout<<d.pushFront(5)<<endl;
    cout<<d.pushRear(15)<<endl;
    cout<<d.pushFront(8)<<endl;

    cout<<d.popFront()<<endl;
    cout<<d.popRear()<<endl;
}