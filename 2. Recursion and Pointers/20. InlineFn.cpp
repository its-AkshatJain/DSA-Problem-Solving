#include <iostream>
using namespace std;

// Inline functions
// It will replace all the occurence of getMax in main with this code
// No extra memory usage and no function calling
// code - 1 line- accept | 2-3 line - may or may not accept | >3 - not accept 
inline int getMax(int &a,int &b){
    return (a>b) ? a : b;
}

// Default Argument - start variable has default value
// It always starts with rightmost argument
// void print(int arr[], int size =0, int start){   // this will give error
// void print(int arr[], int size =0, int start = 0){   // this is correct
void print(int arr[], int size , int start = 0){
    for(int i=start; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a = 5,b = 6;
    int ans;
    // if(a>b){
    //     ans =a;
    // }else{
    //     ans = b;
    // }

    // Using ternary operator
    // ans = (a>b) ? a : b;
    ans =getMax(a,b);
    cout<<ans<<endl;

    int arr[5] = {1,2,3,4,5};
    print(arr,5,2);
    print(arr,5);

    // Constant variable - we cannot change its value throughout the program
    // you must assign valur to const during declaration else error will be there
    const int i = 5;
    //  A pointer to a constant integer. You can change the address stored in the pointer, but not the value pointed to.
    const int * j = &i;
    // i++;  // this will give error
    cout<<i<<endl;
    j=&a;
    cout<<j<<endl;

    return 0;
}