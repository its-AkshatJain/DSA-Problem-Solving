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

pair<bool,int> isSumTreeFast(Node* root){
    // Base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    
    // For leaf node
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    
    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
    
    bool left = leftAns.first;
    bool right = rightAns.first;
    
    bool condn = root->data == leftAns.second + rightAns.second;
    
    pair<bool,int> ans;
    // ans.second = root->data + leftAns.second + rightAns.second;
    ans.second = 2*root->data;
    if(left && right && condn){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}

bool isSumTree(Node* root) {
    return isSumTreeFast(root).first; 
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Check tree is Sum Tree or not (left right sum equal to current node for each node):"<<isSumTree(root)<<endl;
}