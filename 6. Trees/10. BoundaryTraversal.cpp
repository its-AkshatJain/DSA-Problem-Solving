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

 void traverseLeft(Node* root, vector<int> &ans){
    // Base case 
    // check if root is null or node is leaf node
    if(root == NULL || (root->left == NULL && root->right== NULL)){
        return ;
    }
    
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left, ans);
    }else{
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans){
    if(root == NULL){
        return ;
    }
    
    if(root->left == NULL && root->right== NULL){
        ans.push_back(root->data);
    }
    
    traverseLeaf(root->left, ans);
    
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans){
    // Base case 
    // check if root is null or node is leaf node
    if(root == NULL || (root->left == NULL && root->right== NULL)){
        return ;
    }
    
    if(root->right){
        traverseRight(root->right, ans);
    }else{
        traverseRight(root->left, ans);
    }
    
    // Wapas aagye
    ans.push_back(root->data);
}

vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    ans.push_back(root->data);
    
    // Left Part store/print
    traverseLeft(root->left, ans);
    
    // Leaf Node Traversal
    // left Subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);
    
    // Right Part store/print
    traverseRight(root->right, ans);
    
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 
    // 3 5 
    // 7 11 17

    vector<int> ans = boundary(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}