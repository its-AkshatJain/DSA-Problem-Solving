#include<stdio.h>
// Assume Taylor series of form: 1+p/f   o(n^2)
double e(int x, int n){
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else{
        r = e(x,n-1);
        p=p*x;
        f=f*n;
        return r+(p/f);
    }
}

// Using Horner's rule -recursion  o(n)
double e1(int x, int n){
    static double s = 1;
    if(n==0)
        return s;
    s= 1+ (x*s/n);
    return e1(x,(n-1));
}

// Using Horner's rule -loop
double e2(int x, int n){
    double s = 0;
    for(;n>0;n--){
        s= 1+ (x*s/n);
    }
    return s;
}

int main(){
    double r = e(1,20);
    printf("%lf \n",r);
    // printf("%f \n",r);
    printf("%lf \n",e1(1,20));
    printf("%lf \n",e2(1,20));
    return 0;
}