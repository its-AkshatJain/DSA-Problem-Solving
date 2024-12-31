#include <iostream>
using namespace std;

//It returns array minimum element in a sorted rotated array
int getPivot(int arr[],int size){
    int s=0;
    int e= size -1;
    int mid;
    while(s<e){
        mid= s+(e-s)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return s;
}

int BinarySearch(int arr[],int s,int e, int key){
    int mid;
    while(s<=e){
        mid= s+(e-s)/2; //s+e/2
        if(arr[mid]==key){
           return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
    }
    return -1;
}

//Search in a rotated sorted array
int searchRotated(int arr[],int size,int key){
    int pivot =getPivot(arr,size);
    if(arr[pivot]<=key && arr[size-1]>=key ){
        return BinarySearch(arr,pivot,size-1,key);
    }else{
        return BinarySearch(arr,0,pivot,key);
    }
}

int main(){
    int arr1[6]={8,17,10,1,3,5};
    cout<<"Search in a rotated sorted array : "<<searchRotated(arr1,6,3)<<endl;
    return 0;
}