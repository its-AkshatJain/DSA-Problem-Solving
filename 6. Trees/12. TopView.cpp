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

 vector<int> topView(Node *root){
    //Your code here
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    // horizontal distance - node data
    map<int, int> topNode;
    // node - horizontal distance
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        // If one value is present for HD do nothing
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    
    for(auto i: topNode){
        ans.push_back(i.second);
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

    vector<int> ans = topView(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}