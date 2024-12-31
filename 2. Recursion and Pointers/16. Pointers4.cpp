#include <iostream>
using namespace std;

void print(int *p){
    cout<<p<<endl;
    cout<<*p<<endl;
}

void update(int *p){
    // p=p+1;
    // cout<<"Inside fn p is :"<<p<<endl;
    *p = *p +1;
}
            // arr[]
void getSum(int *arr, int n){
    // It will not return correct size of array as it is pointer to array
    cout<<"Size of array : "<<sizeof(arr)<<endl;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout<<"Sum :"<<sum<<endl;
}
int main(){
    int value = 5;
    int *p =&value;
    print(p);

    cout<<"Before : "<<p<<" value : "<<*p<<endl;
    update(p);
    cout<<"After : "<<p<<" value : "<<*p<<endl;

    int arr[6] = {1,2,3,4,5,6}; 
    getSum(arr,6);
    // You can send part of the array
    getSum(arr+3,3);

    return 0;
}