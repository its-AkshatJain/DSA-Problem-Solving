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

int LinearSearch(struct Array arr, int key){
    int i;
    for(i=0;i<arr.length;i++){
        if(key == arr.A[i])
            return i;
    }
    return -1;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearchTransposition(struct Array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int LinearSearchMoveToHead(struct Array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main(){
    struct Array arr = {{2,4,6,8,10},10,5};
    Display(arr);

    // printf("\n Search index is %d",LinearSearch(arr,6));
    // printf("\n Search index is %d",LinearSearchTransposition(&arr,6));

    printf("\nSearch index is %d",LinearSearchMoveToHead(&arr,6));

    return 0;
}