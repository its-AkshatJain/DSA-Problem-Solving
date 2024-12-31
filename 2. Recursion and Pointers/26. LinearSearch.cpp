#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){
    // base case
    if(size == 0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }else{
        return linearSearch(arr + 1, size-1,key);
    }
}

int main(){
    int arr2[7]={5,9,4,6,7,3,2};
    cout<<"Key is present or not : "<<linearSearch(arr2,7,3)<<endl;

    return 0;
}