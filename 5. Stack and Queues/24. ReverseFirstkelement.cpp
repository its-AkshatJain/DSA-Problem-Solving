#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    // step 1 : fetch k elements from queue and put into stack
    for(int i=0; i<k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    // step 2 : fetch elements from stack and push them into queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // Step 3 : fetch first n-k element from queue and push them at back
    int t = q.size() - k;
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> ans = modifyQueue(q,3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    // printing reverse queue
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }
    cout<<endl;
}