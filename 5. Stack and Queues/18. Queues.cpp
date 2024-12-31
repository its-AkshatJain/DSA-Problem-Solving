#include <iostream>
#include <queue>
using namespace std;

class Queue {
    int *arr;
    int size;
    int qfront;
    int qrear;

public:
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == qrear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(qrear == size){
            return ;
        }else{
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == qrear){
            return -1;
        }else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear){
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == qrear){
            return -1;
        }else{
            return arr[qfront];
        }
    }
};

int main(){
    // Using STL
    cout<<endl<<"Queue using STL :"<<endl;
    queue<int> q;

    q.push(11);
    cout<<"Front of queue is : "<<q.front()<<endl;
    cout<<"Rear/back of queue is : "<<q.back()<<endl;

    q.push(12);
    q.push(13);
    q.push(14);
    cout<<"Front of queue is : "<<q.front()<<endl;
    cout<<"Rear/back of queue is : "<<q.back()<<endl;

    cout<<"Size of queue is : "<<q.size()<<endl;
    q.pop();
    cout<<"Size of queue is : "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }

    // Using Arrays 
    cout<<endl<<"Queue using Arrays :"<<endl;
    Queue qA;
    qA.enqueue(15);
    qA.enqueue(5);
    qA.enqueue(19);
    qA.enqueue(8);

    cout<<"Popped element is : "<<qA.dequeue()<<endl;

    cout<<"Front of queue is : "<<qA.front()<<endl;

    if(qA.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }

    cout<<endl<<"Deque :"<<endl;
    deque<int> d;
    
    d.push_front(5);
    d.push_back(12);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_back();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();
    if(d.empty()){
        cout<<"Deque is empty"<<endl;
    }else{
        cout<<"Deque is not empty"<<endl;
    }
}