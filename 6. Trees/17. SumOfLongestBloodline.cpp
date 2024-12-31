#include <iostream>
#include <queue>
#include <stack>
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

void solve(Node *root, int sum, int len, int &maxSum, int &maxLen){
    // Base case
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }
    
    sum = sum + root->data;
    
    solve(root->left, sum, len+1, maxSum, maxLen);
    solve(root->right, sum, len+1, maxSum, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int sum = 0;
    int maxSum = INT_MIN;
    
    int len = 0;
    int maxLen = 0;
    
    solve(root,sum,len,maxSum,maxLen);
    return maxSum;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Sum of longest Bloodline of tree (sum of nodes on longest path from root to leaf): "<<sumOfLongRootToLeafPath(root)<<endl;
}