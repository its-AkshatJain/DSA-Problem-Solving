#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Counting Approach
//Using sort fn
//Two pointer approach
void sorting01(int arr[],int size){
    int i=0;
    int j=size-1;
    while(i<j){
        while(arr[i]==0 && i<j){
            i++;
        }
        while(arr[j]==1 && i<j){
            j--;
        }
        if(arr[i]==1 && arr[j]==0 && i<j){
            swap(arr[i],arr[j]);
            j--;
            i++;
        }
    }
}

//Dutch National Flag algorithm
void sorting012(int arr[], int size){
    int low=0;
    int mid=0;
    int high=size-1;
    while(mid<=high){
        switch (arr[mid])
        {
        case 0: 
            swap(arr[low++],arr[mid++]);
            break;
        case 1: 
            mid++;
            break;
        case 2: 
            swap(arr[mid],arr[high--]);
            break;
        }
        // printArray(arr,size);
    }
}

int main(){
    int arr[10]={1,0,0,1,1,1,0,0,0,1};
    sorting01(arr,10);
    printArray(arr,10);
    int arr1[10]={1,0,2,1,2,2,0,1,0,2};
    sorting012(arr1,10);
    printArray(arr1,10);
    
    return 0;
}