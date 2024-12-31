#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout<<"Array : "<<arr<<endl;
    // cout is differently defined for char arrays
    cout<<"Character Array : "<<ch<<endl;

    int *p = &arr[0];
    cout<<"Array Pointer : "<<p<<endl;
    char *c = &ch[0];
    cout<<"Character Array Pointer : "<<c<<endl;

    char temp = 'z';
    char *t = &temp;
    cout<<t<<endl;

    cout<<"Character Array : "<<&ch<<endl;
    char *ptr = &ch[0];
    cout<<"1st : "<<ptr<<endl;
    cout<<"2nd : "<<*ptr<<endl;
    cout<<"3rd : "<<*ptr + 1<<endl;
    cout<<"4th : "<<*(ptr + 1)<<endl;
    
    return 0;
}