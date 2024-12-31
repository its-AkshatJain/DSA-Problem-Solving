#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void swap(int *x, int *y){
    int temp=*x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr){
    int i;
    printf("Elements are :");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int get(struct Array arr, int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}

int set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length){
        return arr->A[index]= x;
    }
    return -1;
}

int max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i=1; i<arr.length; i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct Array arr){
    int min = arr.A[0];
    int i;
    for(i=1; i<arr.length; i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

int sum(struct Array arr){
    int sum = 0;
    int i;
    for(i=0;i<arr.length;i++){
        sum = sum + arr.A[i];
    }
    return sum;
}

int avg(struct Array arr){
    return sum(arr)/arr.length;
}

void reverse(struct Array *arr){
    int *B = (int *)malloc(arr->length*sizeof(int));
    int i,j;
    for(i=arr->length-1, j=0; i>=0; i--,j++){
        B[j]=arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i]=B[i];
    }
}

void reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

void leftShift(struct Array *arr){
    if (arr->length <= 1) {
        // No shift needed for empty or single-element array
        return;
    }
    int i;
    for(i=0;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=0;
}

void rightShift(struct Array *arr){
    if (arr->length <= 1) {
        // No shift needed for empty or single-element array
        return;
    }
    int i;
    for(i=arr->length-1;i>0;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=0;
}

void leftRotate(struct Array *arr){
    if (arr->length <= 1) {
        return;
    }
    int firstElement = arr->A[0];
    int i;
    for(i=0;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length -1]=firstElement;
}

void rightRotate(struct Array *arr){
    if (arr->length <= 1) {
        return;
    }
    int lastElement = arr->A[arr->length-1];
    int i;
    for(i=arr->length-1;i>0;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=lastElement;
}

// void rotate(struct Array *arr)
int main(){
    struct Array arr = {{2,4,6,8,10},10,5};

    // reverse(&arr);
    // reverse2(&arr);
    // leftShift(&arr);
    // rightShift(&arr);
    // leftRotate(&arr);
    // rightRotate(&arr);
    Display(arr);
    // printf("\n%d ",get(arr,3));
    // printf("\n%d ",set(&arr,3,200));
    // Display(arr);
    // printf("\n%d ",max(arr));
    // printf("\n%d ",min(arr));
    // printf("\n%d ",sum(arr));
    // printf("\n%d ",avg(arr));
    return 0;
}