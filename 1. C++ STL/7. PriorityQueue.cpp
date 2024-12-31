#include <iostream>
#include <queue>
using namespace std;

//It is used for maxHeap(max element comes out first) or minHeap.

int main(){
    // max-heap
    priority_queue<int> maxi;

    // min-heap
    priority_queue<int,vector<int>,greater<int>> mini;
    cout<<"Max Heap : "<<endl;
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    cout<<"Size is : "<<maxi.size()<<endl;
    int n = maxi.size();
    for(int i=0;i<n;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

    cout<<"Min Heap : "<<endl;
    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);
    cout<<"Size is : "<<mini.size()<<endl;
    int m = mini.size();
    for(int i=0;i<m;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
}