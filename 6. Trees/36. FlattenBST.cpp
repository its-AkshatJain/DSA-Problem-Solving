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

void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* flatten(Node* root)
{
    vector<int> inorderVal;
    // Store Inorder
    inorder(root, inorderVal);

    int n = inorderVal.size();

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    // 2nd Step
    for(int i=1; i<n; i++){
        Node* temp = new Node(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // 3rd Step
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1
    Node* ans = flatten(root);
    while(ans != NULL){
        cout<<ans->data<<" ";
        ans = ans->right;
    }
    cout<<endl;
}