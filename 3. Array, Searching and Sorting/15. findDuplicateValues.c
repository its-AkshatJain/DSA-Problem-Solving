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

//Sorted Array
void Duplicate(struct Array arr){
    int i;
    int lastDuplicate = 0;
    for(i = 0; i<arr.length-1; i++){
        if(arr.A[i]==arr.A[i+1] && arr.A[i] != lastDuplicate){
            printf("%d ",arr.A[i]);
            lastDuplicate=arr.A[i];
        }
    }
    printf("\n");
}

void countDuplicate(struct Array arr){
    int i,j;
    for(i = 0; i<arr.length-1; i++){
        if(arr.A[i]==arr.A[i+1]){
            j=i+1;
            while(arr.A[j]==arr.A[i])
                j++;
            printf("Duplicate value and its count are %d and %d respectively \n", arr.A[i],j-i);
            i=j-1;
        }
    }
}

// using hash table for both sorted and unsorted array
void hashDuplicate(struct Array arr){
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
        hash[arr.A[i]]++;
    }
    for(i=0;i<=max;i++){
        if(hash[i]>1){
            printf("Duplicate value and its count are %d and %d respectively \n", i,hash[i]);
        }
    }
    free(hash);
}

// Unsorted Array
void DuplicateInUnsorted(struct Array arr){
    int i,j;
    for(i=0;i<arr.length-1;i++){
        int count=1;
        if(arr.A[i]!=-1){
            for(j=i+1;j<arr.length;j++){
                if(arr.A[j]==arr.A[i]){
                    count++;
                    arr.A[j]=-1;
                }
            }
            if(count>1){
                printf("Duplicate value and its count are %d and %d respectively \n", arr.A[i],count);
            }
        }
    }
}

int main(){
    // struct Array arr1 = {{1,3,3,4,6,6,6,8,9},10,9};
    struct Array arr2 = {{1,2,4,2,8,4,1,4,3},10,9};
    // struct Array arr3 = {{3,1,4,6,8},10,5};
    // Display(arr1);
    // Duplicate(arr1);
    // countDuplicate(arr1);
    // hashDuplicate(arr1);
    DuplicateInUnsorted(arr2);

    return 0;
}