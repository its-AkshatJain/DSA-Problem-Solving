#include <iostream>
#include <queue>
#include <stack>
#include <map>
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

void morrisTraversalInorder(Node* root){
    if(root == NULL){
        return;
    }
    Node* curr = root;

    while(curr!=NULL){
        // Case 1: if left is NULL
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }else{
            // Case 2: if left is not NULL
            Node* prev = curr->left;
            
            // Now traverse till the last node of this path
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                // Creating temporary link
                prev->right = curr;
                curr = curr->left;
            }else{
                // if prev->right == curr;
                // Removing temporary link
                prev->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
    cout<<endl;
}

void morrisTraversalPreorder(Node* root){
    if(root == NULL){
        return;
    }

    Node* curr = root;

    while(curr!=NULL){
        // Case 1: if left is NULL
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }else{
            // Case 2: if left is not NULL
            Node* prev = curr->left;
            
            // Now traverse till the last node of this path
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                // Creating temporary link
                prev->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }else{
                // if prev->right == curr;
                // Removing temporary link
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    cout<<endl;
}

void morrisTraversalPostorder(Node* root){
    if(root == NULL){
        return;
    }
    stack<int> ans;
    Node* curr = root;

    while(curr!=NULL){
        // Case 1: if right is NULL
        if(curr->right == NULL){
            ans.push(curr->data);
            curr = curr->left;
        }else{
            // Case 2: if left is not NULL
            Node* prev = curr->right;
            
            // Now traverse till the last node of this path
            while(prev->left != NULL && prev->left != curr){
                prev = prev->left;
            }

            if(prev->left == NULL){
                // Creating temporary link
                prev->left = curr;
                ans.push(curr->data);
                curr = curr->right;
            }else{
                // if prev->left == curr;
                // Removing temporary link
                prev->left = NULL;
                curr = curr->left;
            }
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Inorder Traversal using Morris traversal is :"<<endl;
    morrisTraversalInorder(root);

    cout<<"Preorder Traversal using Morris traversal is :"<<endl;
    morrisTraversalPreorder(root);

    cout<<"Postorder Traversal using Morris traversal is :"<<endl;
    morrisTraversalPostorder(root);
}