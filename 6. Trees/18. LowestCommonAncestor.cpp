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

Node* lca(Node* root ,int n1 ,int n2 )
{
    // Base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2 ){
        return root;
    }
    
    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);
    
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }else{
        return NULL;
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Node* ans = lca(root, 7, 17);
    cout<<"LCA is: "<<ans->data<<endl;
}