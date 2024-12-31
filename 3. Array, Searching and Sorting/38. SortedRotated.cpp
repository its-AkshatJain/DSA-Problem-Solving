#include <iostream>
using namespace std;

bool check(int nums[], int n) {
    int count = 0;

    // If there is only one greater pair i.e count<=1, the array is sorted and rotated
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            count++;
        }
    }
    if (nums[n - 1] > nums[0]) {
        count++;
    }
    return count <= 1;
}

int main(){
    int arr[5]={3,4,5,1,2};
    int arr1[3]={1,1,1};
    int arr2[5]={3,1,5,9,4};

    cout<<check(arr,5)<<endl;
    cout<<check(arr1,3)<<endl;
    cout<<check(arr2,5)<<endl;
}