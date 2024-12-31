#include <iostream>
using namespace std;

int main(){
    int arr[10] = {23,122,41,67};

    cout<<"Address of first element of array : "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"Address of first element of array : "<<&arr[0]<<endl;

    // It will print array first element
    cout<<"4th : "<<*arr<<endl;

    cout<<"5th : "<<*arr + 1<<endl;
    cout<<"6th : "<<*(arr+1)<<endl;

    // In this way array access the value of other elements
    cout<<"7th : "<<arr[2]<<endl;
    cout<<"8th : "<<*(arr+2)<<endl;

    // Index outer side and array name inner side
    int i = 2;
    cout<<"9th : "<<i[arr]<<endl;
    cout<<"10th : "<<2[arr]<<endl;

    // Difference between array and pointers
    // 1.
    int temp[10] = {1,2};
    cout<<"11th : "<<sizeof(temp)<<endl;
    cout<<"12th : "<<sizeof(*temp)<<endl;
    cout<<"13th : "<<sizeof(&temp)<<endl;

    int *ptr = &temp[0];
    cout<<"14th : "<<sizeof(ptr)<<endl;
    cout<<"15th : "<<sizeof(*ptr)<<endl;
    cout<<"16th : "<<sizeof(&ptr)<<endl;

    // 2.
    int a[20] = {1,2,3,4,5};
    cout<<&a<<endl;  // &a = &a[0] = a these are equal
    int *p = &a[0];
    cout<<&p<<endl; 

    // 3.
    // arr = arr +1; // Error
    int *pptr = &arr[0];
    cout<<"Before : "<<pptr<<endl;
    pptr = pptr + 1;
    cout<<"After : "<<pptr<<endl;
    return 0;
}