#include <iostream>
using namespace std;

bool isSorted(int arr[],int size){
    // Base case
    if(size == 0 || size == 1 ){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }else{
        int remainingPart = isSorted(arr+1 , size-1);
        return remainingPart;
    }
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    // int arr1[7]={5,9,4,6,7,3,2};
    cout<<"Array is sorted or not : "<<isSorted(arr,6)<<endl;

    return 0;
}