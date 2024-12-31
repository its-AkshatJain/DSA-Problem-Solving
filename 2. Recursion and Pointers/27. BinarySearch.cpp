#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int end, int key){
    // base case
    if(start>end){
        return false;
    }
    int mid = start + (end - start)/2;
    if(arr[mid]==key){
        return true;
    }else if(arr[mid]>key){
        return BinarySearch(arr,start,mid-1,key);
    }else{
        return BinarySearch(arr,mid+1,end,key);
    }
}

int main(){
    int arr[6]={1,2,3,4,5,6};
    // int arr1[]={0};
    // int arr2[7]={5,9,4,6,7,3,2};
    cout<<"Key is present or not : "<<BinarySearch(arr,0,5,4)<<endl;

    return 0;
}