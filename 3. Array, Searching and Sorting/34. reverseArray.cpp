#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr[], int size){
    for(int i=0,j=size-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    }
}

// If we have given position m after which we have to start reversing
void reverseArrayM(int arr[], int size,int m){
    for(int i=m+1,j=size-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    }
}

int main(){
    int arr1[5]={1,2,3,4,5};
    // reverseArray(arr1,5);
    // printArray(arr1,5);

    reverseArrayM(arr1,5,1);
    printArray(arr1,5);
    return 0;
}