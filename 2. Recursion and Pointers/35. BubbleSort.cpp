#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n){
    // base case
    // array is sorted
    if(n==0 || n==1){
        return ; 
    }
    // for sorting one element - largest element ko end mai rakh diya
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}

int main(){
    int arr[] ={1,5,6,3,2,8,9};
    bubbleSort(arr,7);
    cout<<"Bubble Sort : "<<endl;
    printArray(arr,7);
    return 0;
}