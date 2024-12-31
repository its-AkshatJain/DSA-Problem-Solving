#include <iostream>
using namespace std;

//It returns array minimum element in a sorted rotated array
int getPivot(int arr[],int s,int e){
    // Base case
    if(s>=e){
        return s;
    }

    int mid= s+(e-s)/2;
    // cout<<mid<<endl;
    if(arr[mid]>=arr[0]){
        s=mid+1;
        return getPivot(arr,s,e);
    }else{
        e=mid;
        return getPivot(arr,s,e);
    }
}

int main(){
    // int arr1[6]={8,17,10,1,3,5};
    int arr1[7]={8,17,1,3,5,6,7};
    // int arr1[6]={1,2,3,4,5,6};
    cout<<"Pivot index (It returns array minimum element in a sorted rotated array) is :"<<getPivot(arr1,0,7)<<endl;
}