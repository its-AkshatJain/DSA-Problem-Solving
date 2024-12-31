#include <iostream>
using namespace std;

int getSum(int arr[], int size){
    // base case
    if(size == 0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int sum = arr[0] + getSum(arr+1,size-1); 
    return sum;
    // return arr[0] + getSum(arr+1,size-1);    
}

int main(){
    // int arr[6]={1,2,3,4,5,6};
    // int arr1[]={0};
    int arr2[7]={5,9,4,6,7,3,2};
    cout<<"Sum of elements of Array is : "<<getSum(arr2,7)<<endl;

    return 0;
}