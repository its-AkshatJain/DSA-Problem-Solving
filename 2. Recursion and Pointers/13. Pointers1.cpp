#include <iostream>
using namespace std;

// There are different types of pointers in C++, and they are as follows:

// Null Pointers
    // int *p = NULL; or int *p = 0; 
// Double Pointers  
    // pointer to a pointer  int **q = &p; 
// Void Pointers  
    // void *ptr; to store any type and typecasted to any type
    // Pointer dereferencing and arithmetic cannot be done using this. it can be done after typecasting
// Wild Pointers
    // If a pointer points to unknown variable 
    // int *p;
// Dangling Pointer
    // pointer pointing to a memory location that has been freed 
    // free(p); //after calling free() p becomes a dangling pointer
    // p = NULL; //now p no more a dangling pointer.

// * - value at     & - address of
    
int main(){
    int num = 5;
    int *ptr = &num;
    cout<<"Address of num is :"<<&num<<endl;

    cout<<"Value of ptr is :"<<ptr<<endl;
    cout<<"ptr is pointing to value :"<<*ptr<<endl;

    double d = 4.4;
    double *p = &d;
    cout<<"Value of p is :"<<p<<endl;
    cout<<"p is pointing to value :"<<*p<<endl;

    // Size of pointer is fixed i.e 8 as it stores address
    cout<<"Size of interger : "<<sizeof(num)<<endl;
    cout<<"Size of ptr (of int type) : "<<sizeof(ptr)<<endl;
    cout<<"Size of p (of double type) : "<<sizeof(p)<<endl;

    // pointer to int is created pointing to some garbage address
    // int *pp;   // Never do this
    int *pp = 0;   //You can do this
    // int *pp = NULL;
    // cout<<*pp<<endl;
    int i = 6;
    pp = &i;
    cout<<"Value of pp is :"<<p<<endl;
    cout<<"pp is pointing to value :"<<*p<<endl;

    // Copying the pointer
    int *q = pp;
    cout<<pp<<" - "<<q<<endl;
    cout<<*pp<<" - "<<*q<<endl;

    // Checking increment of values
    int n = 3;
    int a = num;
    cout<<"Before : "<<n<<endl;
    a++;
    cout<<"After : "<<n<<endl;

    int *pptr = &n;
    cout<<"Before : "<<n<<endl;
    (*pptr)++;
    cout<<"After : "<<n<<endl;

    // Important concept
    int *t = &i;
    *t = *t +1;
    cout<<*t<<endl;
    cout<<"Before : "<<t<<endl;
    t=t+1;   // it moves the pointer to next integer
    cout<<"After : "<<t<<endl;
}