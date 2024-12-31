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

void inOrder(Node* root, int &cnt){
    // Base case
    if(root == NULL){
        return ;
    }

    // Inorder LNR
    inOrder(root->left,cnt);

    // Leaf node
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }

    inOrder(root->right,cnt);
}

int noOfLeafNodes(Node *root){
    int count = 0;
    inOrder(root,count);
    return count;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"No of leaf nodes :"<<noOfLeafNodes(root)<<endl;
}