#include <iostream>
#include <deque>
using namespace std;

// It is a doubly ended queue
// We can perform operations from both side of array

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_front(3);
    for(int i: d){
        cout<<i<<" ";
    }
    cout<<endl;

    // d.pop_back();
    // d.pop_front();
    // for(int i: d){
    //     cout<<i<<" ";
    // }

    cout<<"First element : "<<d.front()<<endl;
    cout<<"Last element : "<<d.back()<<endl;

    cout<<"Element at index 1 : "<<d.at(1)<<endl;
    cout<<"Empty or not : "<<d.empty()<<endl;

    deque<int> :: iterator iter = d.begin();
    d.insert(iter, 35);
    deque<int> :: iterator it = d.end();
    d.insert(it, 17);
    cout<<"After inserting : "<<endl;
    for(int i : d){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Before erase : "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);  //To delete 1st element Capacity remains same O(n)
    cout<<"After erase : "<<d.size()<<endl;
    for(int i : d){
        cout<<i<<" ";
    }
    cout<<endl;

}