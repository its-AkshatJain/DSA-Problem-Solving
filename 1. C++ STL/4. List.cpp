#include <iostream>
#include <list>
using namespace std;

//It is a doubly linked List
//We cannot access  any element directly like array we need to traverse to that element

int main(){
    list<int> l;

    list<int> a(l);  //copies l

    list<int> l(5,100); ////it creates a list of size 5 ans initialises it with 100
    l.push_back(4);
    l.push_front(6); 

    for(int i : l){
        cout<<i<<" ";
    }
    cout<<endl;
    // l.pop_back();
    // l.pop_front();

    // You can use fn like empty(), begin(),end(), front(),back().

    cout<<"Before erase : "<<l.size()<<endl;
    l.erase(l.begin());  //To delete 1st element Capacity remains same O(n)
    cout<<"After erase : "<<l.size()<<endl;
    for(int i : l){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Size of list : "<<l.size()<<endl;
    return 0;
}