#include <iostream>
using namespace std;

// x^n
int power(int x,int n){
    // Base Case
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    // Recursive Call
    // int ans = power(x,n/2);
    int ans = power(x,n>>1);
    
    // if(n%2==0){
    //     // even
    //     return ans*ans;
    //     // n>>1 is same as n/2
    // }else{
    //     return x*ans*ans;
    // }

    if(n&1){
        // odd
        return x*ans*ans;
        // n>>1 is same as n/2
    }else{
        return ans*ans;
    }
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<x<<" to the power "<<n<<" is : "<<power(x,n)<<endl;
}