#include<stdio.h>

int fact(int n){
    if (n>=0){
        if(n==0)
            return 1;
        return fact(n-1)*n;
    }
    else{
        return (-1);
    }
}

int Ifact(int n){
    int i, f=1;
    for(i=1; i<=n; i++){
        f=f*i;
    }
    return f;
}

int main(){
    int r= fact(5);
    printf("%d \n", r);
    int p= Ifact(5);
    printf("%d \n", p);
    return 0;
}