#include <iostream>
#include <vector>
using namespace std;

//It doubles its size when a new element arrives and it has no space left to keep that element.
// It has dynamic size.

int main(){
    vector<int> v;

    vector<int> a(5,1);  //it creates a vector of size 5 ans initialises it with 1

    vector<int> lasr(a); //it copies all the element of a

    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    cout<<"First element : "<<v.front()<<endl;
    cout<<"Last element : "<<v.back()<<endl;

    cout<<"Element at index 1 : "<<v.at(1)<<endl;

    cout<<"Before pop :"<<endl;
    for(size_t i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    v.pop_back();
    cout<<"After pop :"<<endl;
    // variable  vector array  --- variable will get value of vector one by one. 
    for(int i : v){
        cout<<i<<endl;
    }

    // Iterator and Inserting
    vector<int> :: iterator iter = v.begin();
    v.insert(iter, 35);
    vector<int> :: iterator it = v.end();
    v.insert(it, 17);
    cout<<"After inserting : "<<endl;
    for(int i : v){
        cout<<i<<endl;
    }

    cout<<"Empty or not : "<<v.empty()<<endl;

    cout<<"Size before clear : "<<v.size()<<endl;
    v.clear();  //it clears the size but the capacity remains same
    cout<<"Size After clear : "<<v.size()<<endl;

    return 0;
}
