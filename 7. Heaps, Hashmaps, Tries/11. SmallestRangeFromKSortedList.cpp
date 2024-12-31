#include <iostream>
#include<queue>
#include<vector>
#include <limits.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Step 1 : Create a minHeap for starting element of each list and track mini/maxi
    for(int i=0; i<k; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;
    // Process ranges
    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();
        // mini fetch
        mini = temp->data;

        // range or answer updation
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        // next element exists update Max 
        if(temp->col + 1 < n){
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col+1));
        }else{
            // If any list is exhausted, break
            break;
        }
    }
    // returning the difference of sum values
    return (end - start) + 1;
}

int main() {
    vector<vector<int>> kArrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int k = kArrays.size();
    int n = kArrays[0].size(); // Assuming all lists have the same length

    int result = kSorted(kArrays, k, n);

    cout << "The smallest range is: " << result << endl;

    return 0;
}