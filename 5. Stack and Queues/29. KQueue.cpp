#include <iostream>
#include <queue>
using namespace std;

class kQueue{
    int k;  // no of queue
    int n; // size of arr
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

public:
    // Constructor
    kQueue(int n, int k){
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int data, int qn){
        // OverFlow condition
        if(freeSpot == -1){
            cout<<"No empty space is present "<<endl;
        }

        // find first free index
        int index = freeSpot;

        // Update freeSpot
        freeSpot = next[index];

        // if first element of qn
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }else{
            next[rear[qn-1]] = index;
        }

        // Update next
        next[index] = -1;

        // Update rear
        rear[qn-1] = index;

        // Push element to index
        arr[index] = data;
    }

    int dequeue(int qn){
        // UnderFlow
        if(front[qn-1] == -1){
            cout<<"UnderFlow condition"<<endl;
            return -1;
        }

        // Find index to pop
        int index = front[qn-1];

        // update front (front ko aage badhao)
        front[qn-1] = next[index];

        // Manage freeSpots
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main(){
    kQueue q(10,3);

    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    cout<<q.dequeue(1)<<endl;
}