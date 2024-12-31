#include <iostream>
#include <queue>
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

bool isBST(Node *root, int min, int max){
    // Base case
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }else{
        return false;
    }
}

bool validateBST(Node *root) {
    // Write your code here
    return isBST(root, INT_MIN, INT_MAX);
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1

    cout<<"Input Tree is BST or not : "<<validateBST(root);
}