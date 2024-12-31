#include <iostream>
#include <queue>
using namespace std;

 long long minCost(long long arr[], long long n) {
    // Creating min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq; 
    
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }
    
    long long cost = 0;
    
    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();
        
        long long b = pq.top();
        pq.pop();
        
        long long sum = a+b;
        cost += sum;
        
        pq.push(sum);
    }
    
    return cost;
}

int main(){
    long long arr[4] = {4, 3, 2, 6};

    cout<<"Minimum cost of ropes is : "<<minCost(arr,4)<<endl;
}