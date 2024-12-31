#include <iostream>
using namespace std;

//It returns array minimum element in a sorted rotated array
int Sqrt(int n,int s,int e, int ans=0){
    // Base case
    if(s>e){
        return ans;
    }
    long long mid = s+(e-s)/2;
    long long square = mid*mid;

    // cout << "s: " << s << ", e: " << e << ", mid: " << mid << ", square: " << square << ", ans: " << ans << endl; // Debug print 
    if(square==n){
        return mid;
    }else if(square>n){
        return Sqrt(n,s,mid-1,ans);
    }else{
        return Sqrt(n,mid+1,e,mid);
    }
}

int main(){
    int n = 10;
    cout<<"Square root is :"<<Sqrt(n,0,n)<<endl;
}