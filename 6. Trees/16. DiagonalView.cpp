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

// T.c and S.c - O(n)
vector<int> diagonal(Node *root)
{
    vector <int> ans;
    if(root==NULL){ 
        return ans;
    }
    
    // To store left nodes of a current node
    queue <Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        
        while(temp!=NULL){
            // Push left nodes to queue
            if(temp->left){
                q.push(temp->left);
            }
            
            // Push current element to ans
            ans.push_back(temp->data);
               
            temp = temp->right;
        }
    }
   return ans;
}

// Function to return a list containing elements of right view of the binary tree.
// this method is correct but not submitted on gfg
vector<int> DiagonalView(Node *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    // To Store diagonal level and corresponding elements
    map<int, vector<int>> diagonalNodes;
    queue<pair<Node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int dLvl = temp.second;

        diagonalNodes[dLvl].push_back(frontNode->data);

        if(frontNode->left){
            // when going left increment diagonal level by one
            q.push(make_pair(frontNode->left, dLvl+1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, dLvl));
        }
    }

    for(auto i: diagonalNodes){
        for(auto j: i.second){
            ans.push_back(j);
        }
    }

    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 
    // 3 5 
    // 7 11 17
    vector<int> ans1 = diagonal(root);
    for(auto i: ans1){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> ans2 = DiagonalView(root);

    for(auto i: ans2){
        cout<<i<<" ";
    }
    cout<<endl;
}