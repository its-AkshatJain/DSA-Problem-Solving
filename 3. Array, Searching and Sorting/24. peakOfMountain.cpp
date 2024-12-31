#include <iostream>
using namespace std;

int peakIndexInMountainArray(int arr[],int size) {
        int s=0;
        int e= size-1;
        int mid=0;
        while(s<e){
            mid= s+(e-s)/2;
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }else{
                e=mid;
            }
        }
        return s;
}

int main(){
    int arr[5]={1,2,3,1,0};
    cout<<"Peak index in a Mountain Array :"<<peakIndexInMountainArray(arr,5)<<endl;
}