#include <stdio.h>

void fun(int n){
    if(n>0){
        fun(n-1);        //Head Recursion
        printf("\n %d", n);
        // fun(n-1);     //Tail Recursion
    }
}

int main(){
    int x=3;
    fun(x);

    return 0;
}