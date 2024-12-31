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

Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1

    cout<<"Min element is : "<<minVal(root)->data<<endl;
    cout<<"Max element is : "<<maxVal(root)->data<<endl;
}