#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void append(struct Array *arr,int x){
    if(arr->length < arr->size)
        // arr->A[arr->length]=x;
        // arr->length++;
        arr->A[arr->length++]=x;
}

void insert(struct Array *arr,int index,int x){
    int i;
    if(index>=0 && index <= arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i]= arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int delete(struct Array *arr,int index){
    int i, x=0;
    if(index>=0 && index <= arr->length){
        x= arr->A[index];
        for(i=index; i<arr->length-1; i++){
            arr->A[i]=arr->A[i+1];
        } 
        arr->length--;
        return x;
    }
    return 0;
}

void Display(struct Array arr){
    int i;
    printf("Elements are :");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int main(){
    struct Array arr = {{2,4,6,8},10,4};
    
    // append(&arr,10);
    // insert(&arr,4,20);
    // printf("%d \n",delete(&arr,1));
    Display(arr);

    int ch;
    int x, index;
    do
    {
    printf("\n\nMenu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("enter you choice ");
    scanf("%d",&ch);
    
    switch(ch){
        case 1: printf("Enter the index and element to insert :");
        scanf("%d%d",&index,&x);
        insert(&arr,index,x);
        break;
        case 2: printf("Enter the element to delete :");
        scanf("%d",&x);
        delete(&arr,x);
        break;
        case 3: Display(arr);
    }
    }while(ch<4);

    return 0;
}