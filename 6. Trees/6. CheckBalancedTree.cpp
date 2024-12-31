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

int height(Node* root) {
    // Base case
    if(root==NULL){
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    int ans = max(left,right) + 1;
    
    return ans;
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Base Case
    if(root == NULL){
        return true;
    }
    
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <=1;
    
    if(left && right && diff){
        return true;
    }else{
        return false;
    }
}

// Optimized Approach
pair<bool,int> isBalancedFast(Node *root)
{
    //  Base Case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    
    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);
    
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <=1;
    
    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced2(Node *root)
{
    return isBalancedFast(root).first;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Check tree is balanced or not :"<<isBalanced2(root)<<endl;
}