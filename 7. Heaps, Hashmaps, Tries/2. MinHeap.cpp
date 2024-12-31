#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int smallest = i;
    // As we are using 0 based indexing in this question
    int left = 2*i +1;
    int right = 2*i + 2;

    if(left<n && arr[smallest] > arr[left]){
        smallest = left;
    }

    if(right<n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}


vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
}

int main(){
    vector<int> arr;
    arr.push_back(50);
    arr.push_back(55);
    arr.push_back(53);
    arr.push_back(52);
    arr.push_back(51);
    arr.push_back(60);

    vector<int> ans = buildMinHeap(arr);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}