#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// We have to move all the zeros to right and keep the order of remaining elements same
void moveZerosB(int arr[],int size){   //Love Babber method
    int i=0;
    for(int j=0;j<size;j++){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
}

void moveZeros(int arr[],int size){   //Akshat method
    int i=0;
    for(int j=0;j<size;j++){
        if(arr[j]!=0){
            arr[i]=arr[j];
            i++;
        }
    }
    for(int k=i;k<size;k++){
        arr[k]=0;
    }
}

int main(){
    int arr1[]={1,0,0,2,3,0,4,5,0};

    moveZeros(arr1,9);
    printArray(arr1,9);

    moveZerosB(arr1,9);
    printArray(arr1,9);
    return 0;
}


