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

// Using iteration - it uses constant space and logn time
bool searchInBST(Node *root, int x) {
    if(root == NULL){
        return false;
    }

    Node *temp = root;
    while(temp!=NULL){
        if(temp->data == x){
            return true;
        }

        if(temp->data > x){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return false;
}

// Using iteration - it uses extra space and logn time
bool searchInBSTRecursive(Node *root, int x) {
    // Base case
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    if(root->data > x){
        // left part
        return searchInBSTRecursive(root->left, x);
    }else{
        // right part
        return searchInBSTRecursive(root->right, x);
    }
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 10 8 21 7 27 5 4 3 -1

    cout<<"Search 27 in BST : "<<searchInBST(root,27)<<endl;
    cout<<"Search 3 in BST : "<<searchInBST(root,3)<<endl;
}