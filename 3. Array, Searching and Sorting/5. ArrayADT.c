#include<stdio.h>
#include<stdlib.h>

//Using Heap (Dynamic memory)
struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements are :");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int main(){
    struct Array arr;
    int n,i;

    printf("Enter the size of Array :");
    scanf("%d",&arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter the number of numbers :");
    scanf("%d",&n);

    printf("Enter the numbers :");
    for(i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length = n;

    Display(arr);

    return 0;
}

//Using Array (Static memory)
// struct Array{
//     int A[20];
//     int size;
//     int length;
// };

// void Display(struct Array arr){
//     int i;
//     printf("Elements are :");
//     for(i=0;i<arr.length;i++)
//         printf("%d ",arr.A[i]);
// }

// int main(){
//     struct Array arr = {{2,4,6,8},20,4};
    
//     Display(arr);

//     return 0;
// }