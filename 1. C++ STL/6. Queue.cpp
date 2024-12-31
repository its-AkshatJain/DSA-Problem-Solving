#include <iostream>
#include <queue>
using namespace std;

//It follows First in first out FIFO.

int main(){
    queue<string> q;

    q.push("Akshat");
    q.push("Anuj");
    q.push("Kumar");

    cout<<"First Element : "<<q.front()<<endl;
    q.pop();
    cout<<"First Element : "<<q.front()<<endl;

    cout<<"Size of Queue : "<<q.size()<<endl;

    cout<<"Empty or not : "<<q.empty()<<endl;
}