#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<" : "<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for inserting in right of "<<data<<" : "<<endl;
    root->right = buildTree(root->right);

    return root;
}

// T.C - O(n^2)   S.C - O(height)
 void solve(Node* root, int k, int &count, vector<int> path){
    if(root == NULL){
        return;
    }
    
    path.push_back(root->data);
    
    // left
    solve(root->left, k, count, path);
    // right
    solve(root->right, k, count, path);
    
    int sum = 0;
    int size = path.size();
    for(int i=size-1; i>=0; i--){
        sum += path[i];
        if(sum==k){
            count++;
        }
    }
    
    path.pop_back();
}

int sumK(Node *root, int k) {
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}

// T.C - O(n)   S.C - O(height)
void solve2(Node* root, int k,int currentSum, unordered_map<int,int> &prefixPathSum, int &count){
    if(root == NULL){
        return;
    }
    
    currentSum += root->data;
    
    // If the current sum is equal to the target sum, increment the count
    if(currentSum == k){
        count++;
    }

    // Check if there is a subpath (from the root to current node) which sums to k
    // currentSum - prefixSum = k
    if(prefixPathSum.find(currentSum - k) != prefixPathSum.end()){
        count += prefixPathSum[currentSum - k];
    }

    // Add the current sum to the map
    prefixPathSum[currentSum]++;

    // left
    solve2(root->left, k, currentSum, prefixPathSum, count);
    // right
    solve2(root->right, k, currentSum, prefixPathSum, count);
    
    // Remove the current sum from the map before returning to the parent node
    prefixPathSum[currentSum]--;
}

int sumK2(Node *root, int k) {
    unordered_map<int,int> prefixPathSum;   
    int count = 0;
    solve2(root,k, 0, prefixPathSum, count);
    return count;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"No. of Sum of K paths in a tree : "<<sumK(root,4)<<endl;
    cout<<"No. of Sum of K paths in a tree : "<<sumK2(root,4)<<endl;
}