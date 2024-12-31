#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int firstOccurence(int arr[],int size, int key){
    int s=0;
    int e=size-1;
    int mid, ans=-1;
    while(s<=e){
        mid= s+(e-s)/2; //s+e/2
        if(arr[mid]==key){
            ans = mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
    }
    return ans;
}

int lastOccurence(int arr[],int size, int key){
     int s=0;
    int e=size-1;
    int mid, ans=-1;
    while(s<=e){
        mid= s+(e-s)/2; //s+e/2
        if(arr[mid]==key){
            ans = mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
    }
    return ans;
}

void firstAndLastPosition(int arr[], int n, int k)
{
    // Write your code here
    int p[2] = {0};
    p[0] = firstOccurence(arr,n,k);
    p[1] = lastOccurence(arr,n,k);
    printArray(p,2);
}

int noOfOccurence(int arr[], int size, int key){
    int count= (lastOccurence(arr,size,key)-firstOccurence(arr,size,key))+1;
    return count;
}

int main(){
    int arr[5]={1,2,3,3,5};
    cout<<"First occurence is at index: "<<firstOccurence(arr,5,3)<<endl;
    cout<<"Last occurence is at index: "<<lastOccurence(arr,5,3)<<endl;
    cout<<"First and Last occurence is at index: ";
    firstAndLastPosition(arr,5,3);
    cout<<"No. of occurence of key: "<<noOfOccurence(arr,5,3)<<endl;
    return 0;
}