#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int n)
{   
    // Write your code here.
    for(int i=0; i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    int arr[] ={1,5,6,3,2,8,9};
    selectionSort(arr,7);
    cout<<"Selection Sort : "<<endl;
    printArray(arr,7);
    return 0;
}