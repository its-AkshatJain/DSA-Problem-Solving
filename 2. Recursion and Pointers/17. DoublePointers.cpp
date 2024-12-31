#include <iostream>
using namespace std;

void update(int **p2){
    // p2 = p2 + 1;
    // kuch change nhi hoga kyoki main fn mai woh hi rahege address pe update nhi kar rhe hai

    // *p2 = *p2+1;
    // change hoga p2 jisko point kar rha hai uski valuse update hogi

    **p2 = **p2 + 1;
    // change hoga
}

int main(){
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout<<"Value of p : "<<p<<endl;
    cout<<"Address of p : "<<&p<<endl;
    cout<<"Value of p2 : "<<p2<<endl;
    cout<<"p2 is pointing to value : "<<*p2<<endl;

    // To print value of i
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

    // To print value of p
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;

    // To print value of p2
    cout<<&p<<endl;
    cout<<p2<<endl;


    cout<<"Before : "<<i<<endl;
    cout<<"Before : "<<p<<endl;
    cout<<"Before : "<<p2<<endl;
    update(p2);
    cout<<"After : "<<i<<endl;
    cout<<"After : "<<p<<endl;
    cout<<"After : "<<p2<<endl;

    return 0;
}