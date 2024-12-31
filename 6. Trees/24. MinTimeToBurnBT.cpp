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

Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
    Node* res = NULL;
    
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        
        if(front->data == target){
            res = front;
        }
        
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node* root, map<Node*, Node*> &nodeToParent){
    map<Node*, bool> visited;
    queue<Node*> q;  //To store which node to visit next
    
    q.push(root);
    visited[root] = true;
    
    int ans = 0;
    
    while(!q.empty()){
        int size = q.size();
        bool flag = 0;
        // process neighbouring nodes
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();
            
            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if(flag == 1){
            ans++;
        }
    }
    return ans;
}

int minTime(Node* root, int target) 
{
    // Algo:
    // Step 1: Create parent Mapping
    // Step 2: Find target node
    // Step 3: Burn the tree in the min time
    
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root,target,nodeToParent);
    
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Min time to burn binary tree is : "<<minTime(root,17)<<endl;
}