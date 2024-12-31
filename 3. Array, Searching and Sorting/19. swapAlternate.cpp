#include <iostream>
using namespace std;

void swapAlternate(int arr[], int length){
    for(int i=0;i<length; i=i+2){
        if(i+1<length){
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[6]={5,3,7,2,8,1};
    int arr1[5]={5,3,7,2,8};
    swapAlternate(arr,6);
    swapAlternate(arr1,5);

    return 0;
}