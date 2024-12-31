#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* &root, int d){
    // Base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(root->data < d){
        // right part me insert karna hai
        root->right = insertInBST(root->right, d);
    }

    if(root->data > d){
        // left part me insert karna hai
        root->left = insertInBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;

    while(data != -1){
        root = insertInBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                // We have pushed NULL to seperate each level element
                q.push(NULL);
            }
        }else{
            cout<<front->data<<" ";

            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }
        }
    }
    cout<<endl;
}

void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* inorderToBST(int s, int e,vector<int> &in){
    // Base case
    if(s>e){
        return NULL;
    }

    int mid = (s + e)/2;

    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);

    return root;
}

Node* balancedBst(Node* root) {
    vector<int> inOrderVal;
    inorder(root, inOrderVal);

    Node* ans = inorderToBST(0, inOrderVal.size()-1, inOrderVal);
    return ans;
}


int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1
    
    Node* ans = balancedBst(root);
    levelOrderTraversal(ans);
}