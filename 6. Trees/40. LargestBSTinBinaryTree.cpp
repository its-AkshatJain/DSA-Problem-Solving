#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* &root, int d){
    // Base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(root->data < d){
        // right part me insert karna hai
        root->right = insertInBST(root->right, d);
    }

    if(root->data > d){
        // left part me insert karna hai
        root->left = insertInBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;

    while(data != -1){
        root = insertInBST(root, data);
        cin>>data;
    }
}

class info{
 public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node * root, int &ans){
    // Base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currentNode;
    currentNode.size = left.size + right.size + 1;
    currentNode.maxi = max(root->data, right.maxi);
    currentNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currentNode.isBST = true;
    }else{
        currentNode.isBST = false;
    } 

    // update answer
    if(currentNode.isBST){
        ans = max(ans, currentNode.size);
    }

    return currentNode;
}

int largestBST(Node * root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1
   
    cout<<"Largest Size of BST in a binary tree : "<<largestBST(root)<<endl;
}