#include <stdio.h>

int main(){
    int A[4]={1,2,3,4};
    // int B[5];
    // int C[6]={1,3,5};
    // int D[4]={0};
    // int E[] = {1,2,3,4,5,6,7};
    // int i; //signed variable
    size_t i; //unsigned variable

    for(i=0; i < (sizeof(A)/sizeof(A[0])); i++){
        printf("%d \n",A[i]);  //to print values
    }

    for(i=0; i < (sizeof(A)/sizeof(A[0])); i++){
        //to print address
        // printf("%u \n",&A[i]); //%u is usede for unsigned variable
        printf("%p \n",&A[i]);    //%p for pointer address
        // printf("%p \n",(void*)&A[i]);
    }

    return 0;
}



    