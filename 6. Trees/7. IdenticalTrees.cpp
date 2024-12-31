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

bool isIdentical(Node *r1, Node *r2)
    {
        //Base Case
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        if(r1 == NULL && r2!=NULL){
            return false;
        }
        
        if(r1!=NULL && r1==NULL){
            return false;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        bool value = r1->data == r2->data;
        
        if(left && right && value){
            return true;
        }else{
            return false;
        }
    }


int main(){
    Node* root1 = NULL;
    root1 = buildTree(root1);
    // 1 2 -1 -1 3 -1 -1
    Node* root2 = NULL;
    root2 = buildTree(root2);

    cout<<"Check that trees are identical or not :"<<isIdentical(root1, root2)<<endl;
}