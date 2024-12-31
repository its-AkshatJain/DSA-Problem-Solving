#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque<int> dq;
    vector<long long> ans;
    
    // For first window
    for(int i=0; i<K; i++){
        // Check if element is -ve
        if(A[i] < 0){
            dq.push_back(i);
        }
    }
    
    // store answer for first k sized window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }
    
    // for remaining windows
    for(int i=K; i<N; i++){
        // Removal
        if(!dq.empty() && i - dq.front() >= K){
            dq.pop_front();
        }
        
        // Addition
        if(A[i] < 0){
            dq.push_back(i);
        }
        
        // Store answer
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
 }

 int main(){
    long long int arr[10] = {5,-9,3,6,-5,-1,3,4,-6,2};
    vector<long long> ans = printFirstNegativeInteger(arr,10,2);

    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
 }