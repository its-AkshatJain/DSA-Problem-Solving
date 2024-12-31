#include <stdio.h>

int fact(int n){
    if(n==0)
        return 1;
    return fact(n-1)*n;
}

int nCr(int n, int r){
    int num = fact(n);
    int den = fact(r)*fact(n-r);
    return num/den;
}

// Using pascal triangle
int NCR(int n, int r){
    if(r==0 || r==n)
        return 1;
    return NCR(n-1,r-1) + NCR(n-1,r);
}

int main(){
    printf("Factorial is :%d \n",nCr(5,2));
    printf("Factorial is (using Pascals triangle) :%d \n",nCr(5,2));
    return 0;
}