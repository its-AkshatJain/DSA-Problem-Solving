#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[], int s, int e){
    int pivot = arr[s];

    int count = 0;
    // Count elements smaller than pivot
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    // Place pivot element at correct position
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);

    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[],int s,int e){
    // Base case
    if(s>=e){
        return ;
    }

    // Partition of array
    int p = partition(arr,s,e);

    // Recursive call for left and right part
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[] ={1,5,6,3,2,8,9};
    quickSort(arr,0,6);
    cout<<"Quick Sort : "<<endl;
    printArray(arr,7);

    return 0;
}