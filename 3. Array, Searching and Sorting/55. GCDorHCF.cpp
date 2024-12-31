#include <iostream>
using namespace std;

int gcd(int a,int b){
    
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a=a-b;
        }else{
            b=b-a;
        }
    }
    return a;
}

int main(){
    int gcd_no = gcd(25,625);
    cout<<gcd_no<<endl;

    return 0;
}