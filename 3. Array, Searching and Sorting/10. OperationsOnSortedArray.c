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

void sortedInsert(struct Array *arr, int x)
{
   int i=arr->length-1;
   if(arr->length == arr->size){
    return;
   }
   while(i>=0 && arr->A[i]>x){
    arr->A[i+1] = arr->A[i];
    i--;
   }
   arr->A[i+1]=x;
   arr->length++;
}

int IsSorted(struct Array arr){
    int i;
    for(i=0; i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0; //not sorted
        }
    }
    return 1; //sorted
}

//-ve on left and +ve on right
void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
     while(i<j){
        while(arr->A[i]<0){ i++; }
        while(arr->A[j]>=0){ j--; }
        if(i<j){
            swap(&arr->A[i], &arr->A[j]);
        }
     }
};


void Display(struct Array arr){
    int i;
    printf("Elements are :");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int main(){
    // struct Array arr = {{2,4,6,8,10},10,5};
    struct Array arr1 = {{-15,4,-6,8,-10},10,5};

    // sortedInsert(&arr,5);
    // printf("%d \n",IsSorted(arr));
    Rearrange(&arr1);
    Display(arr1);

    return 0;
}