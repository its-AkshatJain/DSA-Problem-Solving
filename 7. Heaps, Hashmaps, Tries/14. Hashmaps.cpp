#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    // creation
    unordered_map<string, int> m;
    
    // insertion
    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("akshat", 2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;  // this will create new entry with <mera,1>
    m["mera"] = 2;  // this will update existing entry with <mera,1>

    // Search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

    // cout<<m.at("unknownKey")<<endl;
    cout<<m["unknownKey"]<<endl;
    cout<<m.at("unknownKey")<<endl;

    // Size
    cout<<"Size is : "<<m.size()<<endl;

    // to check presence
    cout<< m.count("bro")<<endl;
    cout<< m.count("akshat")<<endl;

    // erase
    cout<<m.erase("babbar")<<endl;
    cout<<"Size is : "<<m.size()<<endl;

    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}