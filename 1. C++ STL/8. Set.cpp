#include <iostream>
#include <set>
using namespace std;

// It stores unique element. It uses binary Search.
// Once you have entered the element you cannot modify it but you can delete it
// It returns element in sorted order
// Unordered set is unsorted and it is faster than sorted.
//insert(), find(), erase(), count() ---> O(logn)

int main(){
    set<int> s;
    s.insert(0);
    s.insert(1);
    s.insert(5);
    s.insert(6);
    s.insert(6);

    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;

    // s.erase(s.begin());
    set<int>::iterator it=s.begin();
    it++;
    s.erase(it);
    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"5 is present or not : "<<s.count(5)<<endl;
    cout<<"-5 is present or not : "<<s.count(-5)<<endl;

    set<int>::iterator itr=s.find(5);
    cout<<"Value present at itr : "<<*itr<<endl;

}