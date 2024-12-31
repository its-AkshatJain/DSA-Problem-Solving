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

void sortedInsert(stack<int> &s,int element){
	// Base case
	if( s.empty() || ( !s.empty() && s.top() < element) ){
		s.push(element);
		return ;
	}

	int num = s.top();
	s.pop();

	// Recursive call
	sortedInsert(s,element);

	s.push(num);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	// Base case
	if(stack.empty()){
		return ;
	}

	int num = stack.top();
	stack.pop();

	// Recursive call to sort remaining array
	sortStack(stack);

	// Insert num in a sorted order
	sortedInsert(stack,num);
}

int main(){
    stack<int> s;
    s.push(-5);
    s.push(8);
    s.push(8);
    s.push(-19);
    s.push(35);
    s.push(40);
    print(s);

    sortStack(s);
    print(s);
}