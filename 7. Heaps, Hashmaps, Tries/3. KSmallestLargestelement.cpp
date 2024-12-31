#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int *arr, int n,int k) {
    // Create a Max heap
    priority_queue<int> pq;
    
    // Step 1 : inset 1st k-1 elements in heap
    for(int i = 0; i<k; i++){
        pq.push(arr[i]);
    }
    
    // Step 2 : now for k to n elements
    for(int i=k; i<n; i++){
        if(arr[i] < pq.top() ){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    int ans = pq.top();
    return ans;
}


int kthLargest(int *arr, int n,int k) {
    // Create a Min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Step 1 : inset 1st k-1 elements in heap
    for(int i = 0; i<k; i++){
        pq.push(arr[i]);
    }
    
    // Step 2 : now for k to n elements
    for(int i=k; i<n; i++){
        if(arr[i] > pq.top() ){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    int ans = pq.top();
    return ans;
}

int main(){
    int arr[5] = {7, 10, 4, 20, 15};

    cout<<"Kth smallest element is : "<<kthSmallest(arr,5,4)<<endl;
    cout<<"Kth largest element is : "<<kthLargest(arr,5,4)<<endl;
}