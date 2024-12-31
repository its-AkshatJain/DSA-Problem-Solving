#include <stdio.h>
//Exponent m^n
int power(int m, int n){
    if(n==0)
        return 1;
    return power(m,n-1)*m;
}

//Efficient way
int power1(int m ,int n){
    if(n==0)
        return 1;
    if(n%2 == 0)
        return power1(m*m,n/2);
    else
        return m*power1(m*m,(n-1)/2);
}

//Using Loops
int power2(int m, int n){
    int i,s=1;
    for(i=0; i<n; i++){
        s=s*m;
    }
    return s;
}

int main()
{
    int r = power(2,5);
    printf("%d \n",r);
    int p = power1(2,5);
    printf("%d \n",p);
    int q = power2(5,3);
    printf("%d \n",q);
    return 0;
}
