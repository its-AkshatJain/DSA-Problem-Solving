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

// Using Recursion
Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    if(root == NULL){
        return NULL;
    }

    if(root->data < P->data && root->data < Q->data){
        // right mai jana hai
        return LCAinaBST(root->right, P, Q);
    }

    if(root->data > P->data && root->data > Q->data){
        // left mai jana hai
        return LCAinaBST(root->left, P, Q);
    }

    return root;
}

// Using Iteration
Node *LCAinaBST2(Node *root, Node *P, Node *Q)
{
    while(root != NULL){
        if(root->data < P->data && root->data < Q->data){
            // right mai jana hai
            root = root->right;
        }else if(root->data > P->data && root->data > Q->data){
            // left mai jana hai
            root = root->left;
        }else{
            return root;
        }
    }
    return root;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1

    Node* n1 = new Node(70);
    Node* n2 = new Node(90);

    Node* ans1 = LCAinaBST(root, n1, n2);
    if (ans1 != NULL) {
        cout << "LCA of a BST (Recursive): " << ans1->data << endl;
    } else {
        cout << "LCA not found (Recursive)" << endl;
    }

    Node* ans2 = LCAinaBST2(root, n1, n2);
    if (ans2 != NULL) {
        cout << "LCA of a BST (Iterative): " << ans2->data << endl;
    } else {
        cout << "LCA not found (Iterative)" << endl;
    }

    delete n1;
    delete n2;
    return 0;
}