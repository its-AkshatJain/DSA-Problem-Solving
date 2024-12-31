#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//using while loop
void insertionSort(int arr[],int n){
    //For rounds 1 to n-1
    for(int i=1;i<n;i++){
        int temp= arr[i];
        int j=i-1;
        //for placing element on right place
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}

//using for loop but it is best done using while loop
void insertionSortf(int arr[],int n){
    //For rounds 1 to n-1
    for(int i=0;i<n-1;i++){
        int temp= arr[i];
        int j=i-1;
        //for placing element on right place
        for(; j>=0;j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}

int main(){
    int arr[] ={1,5,6,3,2,8,9};
    insertionSort(arr,7);
    cout<<"Insertion Sort : "<<endl;
    printArray(arr,7);
    return 0;
}