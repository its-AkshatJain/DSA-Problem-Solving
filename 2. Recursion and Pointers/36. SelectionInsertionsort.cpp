#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int *arr,int n){
    // Base case: if the array is of size 0 or 1, it's already sorted
    if(n==0 || n==1){
        return ;
    }

    int minIndex = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex = i;
        }
    }
    swap(arr[0],arr[minIndex]);
    selectionSort(arr+1,n-1);
}

void insertionSort(int *arr,int n,int i = 1){
    // Base Case
    if(n == 0 || n == 1){
        return ;
    }
    if(i>=n){
        return ;
    }

    int temp = arr[i];
    int j=i-1;
    while(j>=0){
        if(arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }else{
            break;
        }
    }
    arr[j+1] = temp;

    // printArray(arr,n);
    insertionSort(arr,n,i+1);
}


int main(){
    int arr[] ={1,5,6,3,2,8,9};
    selectionSort(arr,7);
    cout<<"Selection Sort : "<<endl;
    printArray(arr,7);

    insertionSort(arr,7,1);
    cout<<"Insertion Sort : "<<endl;
    printArray(arr,7);
    return 0;
}