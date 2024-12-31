#include <iostream>
using namespace std;

        // arr[]
int sum(int *arr, int n){
    int s=0;
    for(int i=0; i<n; i++){
        s += arr[i];
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    // Variable size array
    int *arr = new int[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"Sum is : "<<sum(arr,n)<<endl;

    // delete an array in heap memory
    delete[] arr;
}