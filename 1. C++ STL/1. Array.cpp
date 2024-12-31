#include <iostream>
#include <array>
using namespace std;

// It has same functionality as array so not used much

int main(){
    // int arr[5]={1,2,3,4,5};

    array<int,5> arr1={1,2,3,4,5};

    for(size_t i=0;i<arr1.size();i++){
        cout<<arr1[i]<<endl;
    }

    cout<<"Element at index 3 : "<<arr1.at(3)<<endl;

    cout<<"First element : "<<arr1.front()<<endl;
    cout<<"Last element : "<<arr1.back()<<endl;

    cout<<"Empty or not : "<<arr1.empty()<<endl;
    return 0;
}