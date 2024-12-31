#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(int arr[], int n)
{   
    // Write your code here.
    //for round fron 1 to n-1
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        //for performing task of each round
        //As we are comparing with j+1 so thats why -1 in j range
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(swapped==false){
            //already sorted
            break; 
        }
    }
}

int main(){
    int arr[] ={1,5,6,3,2,8,9};
    bubbleSort(arr,7);
    cout<<"Bubble Sort : "<<endl;
    printArray(arr,7);
    return 0;
}