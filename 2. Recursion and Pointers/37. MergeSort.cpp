#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[],int s,int e){
    int mid = s + (e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copying values
    int mainArrayIndex  = s;
    for(int i=0;i<len1;i++){
        first[i]= arr[mainArrayIndex++];
    }

    mainArrayIndex  = mid+1;
    for(int i=0;i<len2;i++){
        second[i]= arr[mainArrayIndex++];
    }

    // Merge 2 sorted arrays
    mainArrayIndex  = s;
    int index1 = 0;
    int index2 = 0;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }

    delete [] first;
    delete [] second;
}

// Without copying elements to new array
void merge2(int arr[],int s,int e){
    int mid = s + (e-s)/2;
    int index1 = s;
    int index2 = mid+1;

    while(index1<=mid && index2<=e){
        if(arr[index1]<=arr[index2]){
            index1++;
        }else{
            // arr[index2] is smaller than arr[index1]
            int value = arr[index2];
            int idx = index2;
            // right shift the elements between index1 and index2
            while(idx>index1){
                arr[idx]=arr[idx-1];
                idx--;
            }
            arr[index1] = value;

            index1++;
            mid++;
            index2++;
        }
    }
    // printArray(arr,e+1);
}

void merge3(int arr[],int s,int e){
    int mid = s + (e-s)/2;
    int len = e+1;
    // int len2 = e-mid;

    int *temp = new int[len];    // Instead of taking two array you can also take one array and store sorted elements in it 
    
    // Merge 2 sorted arrays
    int i=0;
    int index1 = s;
    int index2 = mid+1;
    while(index1<=mid && index2<=e){
        if(arr[index1]<=arr[index2]){
            temp[i++]=arr[index1++];
        }else{
            temp[i++]=arr[index2++];
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
}

void mergeSort(int arr[],int s,int e){
    // Base Case
    if(s>=e){
        return ;
    }
    int mid = s + (e-s)/2;
    // Sort left array
    mergeSort(arr,s,mid);

    // Sort right array
    mergeSort(arr,mid+1,e);

    // Merge sorted array
    merge2(arr,s,e);
}

int main(){
    int arr[] ={1,5,6,3,2,8,9};
    mergeSort(arr,0,6);
    cout<<"Merge Sort : "<<endl;
    printArray(arr,7);

    return 0;
}