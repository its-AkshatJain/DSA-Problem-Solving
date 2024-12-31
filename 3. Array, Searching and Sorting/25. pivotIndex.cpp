#include <iostream>
using namespace std;

int pivotIndex(int nums[], int size) {
    int totalSum=0;
    for(int i=0;i<size;i++){
        totalSum +=nums[i];
    }
    int leftSum = 0;
    for(int i=0;i<size;i++){
        if(leftSum== totalSum-leftSum-nums[i]){
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

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

int main(){
    int arr[6]={1,7,3,6,5,6};
    cout<<"Pivot index (whose leftSum == rightSum ) is :"<<pivotIndex(arr,6)<<endl;
    int arr1[6]={8,17,10,1,3,5};
    cout<<"Pivot index (It returns array minimum element in a sorted rotated array) is :"<<getPivot(arr1,6)<<endl;
}