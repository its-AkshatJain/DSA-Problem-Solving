#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a, node*b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;

    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;
    
    // Step 2
    while(minHeap.size() > 0){

        node* temp = minHeap.top();
        ans.push_back(temp->data);

        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if(col+1 < kArrays[row].size()){
            node* next = new node(kArrays[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main() {
    // Define the number of sorted arrays
    int k = 3;

    // Define the sorted arrays
    vector<vector<int>> kArrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    // Merge the k sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(kArrays, k);

    // Print the merged array
    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;
}