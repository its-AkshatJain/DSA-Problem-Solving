#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int index){
    // O-based indexing
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    
    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b) {
    // Merge two arrays
    vector<int> ans;
    for(auto i: a){
        ans.push_back(i);
    }
    for(auto i: b){
        ans.push_back(i);
    }
    
    // Step 2 : Build heap using merged array
    int size = ans.size();
    for(int i = (size/2)-1; i>=0; i--){
        heapify(ans, size, i);
    }
    
    return ans;
}

int main(){
    vector<int> a;
    a.push_back(50);
    a.push_back(55);
    a.push_back(53);
    a.push_back(52);
    a.push_back(51);
    a.push_back(60);

    vector<int> b;
    b.push_back(40);
    b.push_back(45);
    b.push_back(43);
    b.push_back(42);
    b.push_back(41);
    b.push_back(70);

    vector<int> ans = mergeHeaps(a,b);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}