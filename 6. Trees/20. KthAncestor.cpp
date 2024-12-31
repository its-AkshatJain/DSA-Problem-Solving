#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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

void solve(Node *root, int node, vector<int> &path,bool &found){
    // Base case
    if(root == NULL || found){
        return ;
    }
    
    path.push_back(root->data);
    
    if(root->data == node){
        found = true;
        return;
    }
    
    solve(root->left,node,path,found);
    solve(root->right,node,path,found);
    
    // backtrack if not found
    if(!found){
        path.pop_back();
    }
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    if(root == NULL){
        return -1;
    }
    
    vector<int> path;
    bool found = false;
    
    solve(root,node,path,found);
    
    int size = path.size();
    
    if(k >= size){
        return -1;
    }
    
    return path[size-k-1];
}


Node* solve2(Node *root, int &k, int node){
    // Base case
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == node){
        return root;
    }
    
    Node* leftAns = solve2(root->left,k,node);
    Node* rightAns = solve2(root->right,k,node);
    
    // wapas aate time /backtrack 
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            // ans Lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            // ans Lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor2(Node *root, int k, int node)
{
    Node *ans = solve2(root,k,node);
    
    if(ans == NULL|| ans->data == node){
        return -1;
    }else{
       return ans->data; 
    }
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Kth ancestor is : "<<kthAncestor(root,1,17)<<endl;
    cout<<"Kth ancestor is : "<<kthAncestor2(root,1,17)<<endl;
}