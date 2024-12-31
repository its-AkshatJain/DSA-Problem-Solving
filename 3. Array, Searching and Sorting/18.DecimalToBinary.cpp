#include <iostream>
#include<math.h>
using namespace std;

void DecimaltoBinary(int n){
    int i=0,ans=0;
    while(n!=0){
        int bit = n&1;
        ans= (bit*pow(10,i)+ans);
        n=n>>1;
        i++;
    }
    cout<<"Binary is : "<<ans<<endl;
}

//Accepting negative input 2s compliment
// void DecimaltoBinaryNegative(int n){
//     if(n<0){
//         n=-n;
//     }
//     int i=0,ans=0;
//     while(n!=0){
//         int bit = n&1;
//         ans= (bit*pow(10,i)+ans);
//         n=n>>1;
//         i++;
//     }
//     cout<<"Binary is : "<<ans<<endl;
//     int complement = (~n) +1;
//     int result = 0;
//     while(complement!=0){
//         int bit = complement&1;
//         result= (result*pow(10,i)+bit);
//         complement=complement>>1;
//         i++;
//     }
// }


void BinarytoDecimal(int n){
    int decimal=0,i=0;
    while(n!=0){
        int digit=n%10;
        if(digit == 1){
            decimal += pow(2,i);
        }
        n=n/10;
        i++;
    }
    cout<<"Decimal is : "<<decimal<<endl;
}

int main(){
    int n,m;
    cout<<"Enter Decimal no. :"<<endl;
    cin>>n;
    DecimaltoBinary(n);
   
    cout<<"Enter Binary no. :"<<endl;
    cin>>m;
    BinarytoDecimal(m);
    return 0;
}