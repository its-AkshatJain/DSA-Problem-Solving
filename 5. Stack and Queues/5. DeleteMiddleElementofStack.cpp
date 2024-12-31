#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>&inputStack,int count, int size){
   // Base case
   if(count == size/2){
      inputStack.pop();
      return ; 
   }

   // Storing elements above middle element
   int num = inputStack.top();
   inputStack.pop();

   // Recursive Call
   solve(inputStack,count+1,size);

   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
   int count  = 0;
   solve(inputStack,count,N);  
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(8);
    s.push(6);
    s.push(19);
    s.push(35);
    // s.push(40);
    print(s);

    // deleteMiddle(s,6);
    deleteMiddle(s,5);
    print(s);
}