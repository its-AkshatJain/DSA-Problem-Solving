#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements are :");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int BinarySearch(struct Array arr, int key){
    int mid;
    int l=0;
    int h= arr.length -1;

    while(l<=h){
        // mid= (l+h)/2;
        mid= l+(h-l)/2;
        if(key == arr.A[mid]){
            return mid;
        }  
        else if(key < arr.A[mid]){
            h=mid-1;
        } 
        else{
            l= mid+1;
        }
    }
    return -1;
}

int rSearch(int a[], int l, int h, int key){
    int mid=0;
    if(l<=h){
        // mid= (l+h)/2;
        mid= l+(h-l)/2;
        if(key == a[mid]){
            return mid;
        }
        else if(a[mid]<key){
            return rSearch(a,mid+1,h,key);
        }
        else{
            return rSearch(a,l,mid-1,key);
        }
    }
    return -1;
}

int main(){
    struct Array arr = {{2,4,6,8,10},10,5};
    Display(arr);

    printf("\nBinary Serach : %d",BinarySearch(arr,8));
    // int a[] = {2,4,6,8,10};
    // printf("\nBinary Search : %d",rSearch(a,0,4,8));

    return 0;
}