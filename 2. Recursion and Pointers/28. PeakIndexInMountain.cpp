#include <iostream>
using namespace std;

int peakIndexInMountainArray(int arr[],int s,int e) {
    // Base case
    if(s>=e){
        return s;
    }
    int mid= s+(e-s)/2;
    if(arr[mid]<arr[mid+1]){
        s=mid+1;
        return peakIndexInMountainArray(arr,s,e);
    }else{
        e = mid;
        return peakIndexInMountainArray(arr,s,e);
    }
}

int main(){
    int arr[5]={1,2,3,1,0};
    // int arr[5]={1,2,3,4,5};
    int arr1[10]={1,2,3,10,30,22,13,5,4,0};
    cout<<"Peak index in a Mountain Array :"<<peakIndexInMountainArray(arr,0,5)<<endl;
    cout<<"Peak index in a Mountain Array :"<<peakIndexInMountainArray(arr1,0,10)<<endl;
}