#include <iostream>
using namespace std;

void sayDigits(int n, string arr[]){
    // Base case
    if(n==0){
        return;
    }
    // Processing
    int digit = n%10;
    n=n/10;
    // cout<<arr[digit]<<" ";  // It will print in reverse order
    // Recursive relation
    sayDigits(n,arr);
    cout<<arr[digit]<<" "; 
}

int main(){
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    sayDigits(412,arr);
}