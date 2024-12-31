#include <iostream>
#include <queue>
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

 void solve(Node *root, vector<int> &ans, int level){
    // Base Case
    if(root == NULL){
        return ;
    }
    
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}



int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 
    // 3 5 
    // 7 11 17

    vector<int> ans = leftView(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}