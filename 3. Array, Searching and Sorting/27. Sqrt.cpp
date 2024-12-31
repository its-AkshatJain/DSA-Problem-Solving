#include <iostream>
using namespace std;

long long int floorSqrt(int n)
{
    // Write your code here.
    int s=0;
    int e=n;
    long long int mid,ans=-1;
    while(s<=e){
        mid= s+(e-s)/2;
        long long int square=mid*mid;

        if(square==n){
            return mid;
        }else if(square>n){
            e=mid-1;
        }else{
            ans=mid;
            s=mid+1;
        }
    }
    return ans;
}

double morePrecise(int n,int precision){
    double factor=1;
    int squrt = floorSqrt(n);
    double ans;
    for(int i=0;i<precision;i++){
        factor = factor/10;
        for(double j=squrt;j*j<=n;j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    int squrt = floorSqrt(n);
    cout<<"Floor Square rt: "<<squrt<<endl;
    cout<<"decimal Square rt: "<<morePrecise(n,3)<<endl;
}