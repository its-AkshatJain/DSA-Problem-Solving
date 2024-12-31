#include <iostream>
using namespace std;

void update2(int &n){
    n++;
}

void update1(int n){
    n++;
}

// Very bad practice as variables of function destroys after fn ends
// It can give abnormal result
int& func(int num){
    int &ans = num;
    return ans;
}

// Very bad practice as variables of function destroys after fn ends
// It can give abnormal result
int* func1(int num){
    int *ans = &num;
    return ans;
}

int main(){
    int a = 5;
    int &b = a;
    a++;
    cout<<a<<endl;
    b++;
    cout<<a<<endl;


    int num = 10;
    update1(num);   // Call by Value
    cout<<num<<endl;
    update2(num);   // Call by Reference
    cout<<num<<endl;

    // int i=12;
    // cout<<func(a)<<endl;  // reference variable // it will show warning

    // cout<<func1(i)<<endl;    // Pointer  // it will show warning 
    // int *z = func1(i);       
    // cout<<*z<<endl;

    return 0;
}