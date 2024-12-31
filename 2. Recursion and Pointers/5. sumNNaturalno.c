#include<stdio.h>

// Using Recursion
int Sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return Sum(n-1) + n;
    }
}

//using formula most efficient 0(1)
int sum(int n){
    return n*(n+1)/2;
}

//using for loop
int SUM(int n){
    int i,s=0;
    for(i=1;i<=n;i++){
        s = s+i;
    }
    return s;
}

int main(){
    int r = Sum(5);
    printf("%d \n",r);
    int s = sum(5);
    printf("%d \n",s);
    int p = SUM(5);
    printf("%d \n",p);
    return 0;
}