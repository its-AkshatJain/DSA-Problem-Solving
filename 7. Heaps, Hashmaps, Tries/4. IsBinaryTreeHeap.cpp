#include <iostream>
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

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root, int index, int cnt){
    if(root == NULL){
        return true;
    }
    
    if(index >= cnt){
        return false;
    }else{
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);
        return (left && right);
    }
}

bool MaxOrder(Node* root){
    // Leaf Node
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    
    if(root->right == NULL){
        return (root->data > root->left->data);
    }else{
        bool left = MaxOrder(root->left);
        bool right = MaxOrder(root->right);
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}
bool isHeap(struct Node* tree) {
    int index = 0;
    int totalCount = countNodes(tree);
    
    if(isCBT(tree, index, totalCount) && MaxOrder(tree)){
        return true;
    }else{
        return false;
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"The given binary tree is heap or not :"<<isHeap(root)<<endl;
}