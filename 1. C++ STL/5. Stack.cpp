#include <iostream>
#include <stack>
using namespace std;

//It follows last in first out LIFO.

int main(){
    stack<string> s;

    s.push("Akshat");
    s.push("Anuj");
    s.push("Kumar");

    cout<<"Stack Top Element : "<<s.top()<<endl;
    s.pop();
    cout<<"Stack Top Element : "<<s.top()<<endl;

    cout<<"Size of Stack : "<<s.size()<<endl;

    cout<<"Empty or not : "<<s.empty()<<endl;
}