#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// Using extra queue
vector<int> rearrangeQueue(queue<int> &q){
    queue<int> firstHalf;
    vector<int> ans;
    
    int halfSize = q.size()/2;
    
    for(int i=0; i<halfSize; i++){
        int val = q.front();
        q.pop();
        firstHalf.push(val);
    }
    // while(halfSize!=0){
    //     int val = q.front();
    //     q.pop();
    //     firstHalf.push(val);
    //     halfSize--;
    // }

    // Now push elements in a interleaved manner
    while(!firstHalf.empty() ){   //&& !secondHalf.empty()
        int val = firstHalf.front();
        firstHalf.pop();
        ans.push_back(val);
        q.push(val);
        
        val = q.front();
        q.pop();
        ans.push_back(val);
        q.push(val);
    }
    
    return ans;
}

// Using extra stack
void rearrangeQueue2(queue<int> &q){
    stack<int> s;

    int halfSize = q.size()/2;

    // Push first half to stack
    for(int i=0; i<halfSize; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Push stack elements to queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // Push first half to the queue (as now first half contains second half elements)
    for(int i=0; i<halfSize; i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // Push first half to stack
    for(int i=0; i<halfSize; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Now push elements in a interleaved manner
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }
}

int main(){
    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    vector<int> ans =  rearrangeQueue(q);
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    rearrangeQueue2(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    // while(!ans.empty()){
    //     cout<<ans.front()<<" ";
    //     ans.pop();
    // }
    // cout<<endl;
    return 0;
}