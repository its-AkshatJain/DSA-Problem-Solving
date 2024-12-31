#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int merge(int arr[],int s,int e){
    int mid = s + (e-s)/2;
    int len = e+1;

    int count = 0;
    int *temp = new int[len];    // Instead of taking two array you can also take one array and store sorted elements in it 
    
    // Merge 2 sorted arrays
    int i=0;
    int index1 = s;
    int index2 = mid+1;
    while(index1<=mid && index2<=e){
        if(arr[index1]<=arr[index2]){
            temp[i++]=arr[index1++];
        }else{
            // right side element of arry is greater
            temp[i++]=arr[index2++];
            count += mid-index1+1;    // Only this line is changed for inversion count
        }
    }

    while(index1<=mid){
        temp[i++]=arr[index1++];
    }
    while(index2<=e){
        temp[i++]=arr[index2++];
    }

    // Copy temp to original array
    for(int i=s;i<=e;i++){
        arr[i]= temp[i-s];
    }

    delete [] temp;

    return count;
}

int mergeSort(int arr[],int s,int e){
    int count = 0;
    // Base Case
    if(s>=e){
        return count;
    }
    int mid = s + (e-s)/2;
    // Sort left array
    count += mergeSort(arr,s,mid);

    // Sort right array
    count += mergeSort(arr,mid+1,e);

    // Merge sorted array
    count += merge(arr,s,e);

    return count;
}

int main(){
    // int arr[] ={1,5,6,3,2,8,9};
    int arr[] = { 1, 20, 6, 4, 5 };
    cout<<"Inversion Count is : "<<mergeSort(arr,0,4)<<endl;
    // printArray(arr,7);


    return 0;
}