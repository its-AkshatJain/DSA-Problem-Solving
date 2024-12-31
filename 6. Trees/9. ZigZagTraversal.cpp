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

vector <int> zigZagTraversal(Node* root){
    // Code here
    vector<int> result;
    if(root == NULL){
        return result;
    }
    
    queue<Node*> q;
    q.push(root);
    
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        // To store elements of each level
        vector<int> ans(size);  
        
        // Process Level
        for(int i=0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();
            
            // Insert the element into ans
            int index = leftToRight ? i : size-i-1;
            ans[index] = frontNode->data;
            
            if(frontNode->left){
                q.push(frontNode->left);
            }
            
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        
        // Change the direction to traverse in zigzag
        leftToRight = !leftToRight;
        
        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 
    // 3 5 
    // 7 11 17

    vector<int> ans = zigZagTraversal(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}