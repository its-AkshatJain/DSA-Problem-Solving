#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int> > M, int a, int b){
    if(M[a][b] == 1){
        return true;
    }else{
        return false;
    }
}

// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> >& M, int n) {
    // code here
    // Step 1 Push lements to stack
    stack<int> s;
    for(int i=0 ; i<n; i++){
        s.push(i);
    }
    
    // Step 2 
    while(s.size()>1){
        int a = s.top();
        s.pop();
        
        int b = s.top();
        s.pop();
        
        if(knows(M,a,b)){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    int ans = s.top();
    
    // Step 3 Verify potential celebrity
    int rowCheck = false;
    int zeroCount = 0;
    for(int i=0; i<n; i++){
        if(M[ans][i] == 0){
            zeroCount++;
        }
    }
    
    if(zeroCount == n){
        rowCheck = true;
    }
    
    int colCheck = false;
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(M[i][ans] == 1){
            oneCount++;
        }
    }
    
    if(oneCount == n-1){
        colCheck = true;
    }
    
    if(rowCheck && colCheck){
        return ans;
    }else{
        return -1;
    }
// return -1;
}

int celebrity2(vector<vector<int> >& M, int n) {
    // code here
    // Step 1 Push lements to stack
    stack<int> s;
    for(int i=0 ; i<n; i++){
        s.push(i);
    }
    
    // Step 2 
    while(s.size()>1){
        int a = s.top();
        s.pop();
        
        int b = s.top();
        s.pop();
        
        // Checking a knows b or not
        if(M[a][b] == 1){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    int ans = s.top();
    
    // Step 3 Verify potential celebrity
    int zeroCount = 0;
    for(int i=0; i<n; i++){
        if(M[ans][i] == 0){
            zeroCount++;
        }
    }
    
    if(zeroCount != n){
        return -1;
    }
    
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(M[i][ans] == 1){
            oneCount++;
        }
    }
    
    if(oneCount != n-1){
        return -1;
    }
    
    return ans;
}

int main(){
    vector<vector<int>> arr = {{0, 1, 0},{0, 0, 0},{0, 1, 0}};
    // cout<<"Celebrity is : "<<celebrity(arr,3)<<endl;
    cout<<"Celebrity is : "<<celebrity2(arr,3)<<endl;
}