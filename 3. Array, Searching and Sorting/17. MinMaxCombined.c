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

//Min Max in single scan
void MinMax(struct Array arr){
    int i;
    int max=arr.A[0];
    int min=arr.A[0];
    for(i=0;i<arr.length;i++){
        if(arr.A[i]<min){
            min= arr.A[i];
        }
        else if(arr.A[i]>max){
            max= arr.A[i];
        }
    }
    printf("Max: %d \nMin: %d \n",max,min);
}

int main(){
    struct Array arr = {{3,2,4,6,8,13,24,5},10,8};
    MinMax(arr);
    return 0;
}