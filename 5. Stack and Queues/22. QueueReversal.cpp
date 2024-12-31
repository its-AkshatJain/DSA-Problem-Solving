#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Using Stack
queue<int> rev(queue<int> q){
    // add code here.
    stack<int> s;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    return q;
}

// Using Recursion
void recursiveReverse(queue<int> &q){
    // Base case
    if(q.empty()){
        return ;
    }

    // Store and remove first element
    int frontElement = q.front();
    q.pop();

    // Recursive call to reverse the remqining queue
    recursiveReverse(q);

    // Add this element to the reversed queue
    q.push(frontElement);
}

queue<int> rev2(queue<int> q){
    recursiveReverse(q);
    return q;
}

int main(){
    queue<int> q;

    q.push(5);
    q.push(26);
    q.push(15);
    q.push(79);
    q.push(30);
    q.push(42);

    queue<int> ans = rev(q);
    // queue<int> ans = rev2(q);

    // printing queue
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