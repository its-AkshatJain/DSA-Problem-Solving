#include <stdio.h>

// no of disc , source, intermediate, destination
void TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n-1,A,C,B);
        //moving from A to C
        printf("(%d,%d) \n",A,C);
        TOH(n-1,B,A,C);
    }
}

int main(){
    // for 3 disc
    TOH(3,1,2,3);
    // for 2 disc
    // TOH(2,1,2,3);
    // for 1 disc
    // TOH(1,1,2,3);
    return 0;
}