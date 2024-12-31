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

void insertAtBottom(stack<int> &s, int num){
    // Base case
    if(s.empty()){
        s.push(num);
        return ;
    }

    int element = s.top();
    s.pop();

    // Recursive call
    insertAtBottom(s,num);

    s.push(element);
}

void reverseStack(stack<int> &stack) {
    // Base case
    if(stack.empty()){
        return ;
    }

    int num = stack.top();
    stack.pop();

    // Recursive call to Reverse remaining Stack
    reverseStack(stack);

    insertAtBottom(stack,num);
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

    reverseStack(s);
    print(s);
}