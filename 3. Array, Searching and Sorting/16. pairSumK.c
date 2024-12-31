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
    printf("\n");
}

void pairSumK(struct Array arr, int k){
    int i,j;
    for(i=0; i<arr.length; i++){
        for(j=i+1; j<arr.length; j++){
            if(arr.A[i] + arr.A[j] == k){
                printf("%d + %d = %d \n",arr.A[i],arr.A[j],k);
            }
        }
    }
}

// using hash table
void pairSumKHash(struct Array arr, int k){
    int i,max=0;
    //finding max element
    for(i=0;i<arr.length;i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    // initialise hash array
    int *hash;
    hash = (int *)malloc((max+1)*sizeof(int));
    for(i=0;i<=max;i++){
        hash[i]=0;
    }

    for(i=0;i<arr.length;i++){
        if(k-arr.A[i]<=max && hash[k-arr.A[i]]>0){
            printf("%d + %d = %d \n",arr.A[i],k-arr.A[i],k);
            // printf("%d",hash[9]);
        }
        hash[arr.A[i]]++;
    }
}

//Sorted Array
void pairSumKSorted(struct Array arr, int k){
    int i=0,j=arr.length-1;
    while(i<j){
        if(arr.A[i]+arr.A[j]==k){
            printf("%d + %d = %d \n",arr.A[i],arr.A[j],k);
            i++;
            j--;
        }
        else if(arr.A[i]+arr.A[j] < k){
            i++;
        }
        else{
            j--;
        }
    }
}

int main(){
    // struct Array arr = {{3,2,4,6,8},10,5};
    struct Array arr1 = {{1,2,3,4,5,6,7,8,9},10,9};
    // pairSumK(arr,10);
    // pairSumKHash(arr,10);
    pairSumKSorted(arr1,10);
    return 0;
}