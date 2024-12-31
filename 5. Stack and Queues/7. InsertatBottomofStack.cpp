#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void solve(stack<int>& myStack, int x) {
    // Base case
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }

    int num = myStack.top();
    myStack.pop();

    // Recursive call
    solve(myStack,x);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}


int main(){
    stack<int> s;
    s.push(5);
    s.push(8);
    s.push(6);
    s.push(19);
    s.push(35);
    s.push(40);
    print(s);

    pushAtBottom(s,100);
    print(s);
}