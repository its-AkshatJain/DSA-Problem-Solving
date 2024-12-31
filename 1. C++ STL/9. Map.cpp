#include <iostream>
#include <map>
using namespace std;

// It stores elements as a key value pair.
// All the keys must be unique. Key can have only one value.
// Value can be same.
// It returns element in sorted order
//insert(), find(), erase(), count() ---> O(logn)
//in case of unordered map implementation using hash table O(1);

int main(){
    map<int,string> m;
    m[1]="Akshat";
    m[6]="Anuj";
    m[3]="Kumar";

    m.insert({5,"Babbar"});
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding 6 : "<<m.count(6)<<endl;

    m.erase(6);
    cout<<"After erase :"<<endl;
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(5);
    cout<<"key and value : "<<(*it).first<<" "<<(*it).second<<endl;
    
}