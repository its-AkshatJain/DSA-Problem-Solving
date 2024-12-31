#include <iostream>
using namespace std;

int factorial(int n){
    long long fact = 1;
    long long m = 1000000007;
    for(int i=1; i<=n;i++){
        fact = (fact * i)%m;
    }
    return fact;
}

int main(){
    cout<<factorial(20)<<endl;

    return 0;
}