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

Node *solve(vector<int> &preorder, int mini, int maxi, int &i) {
    if(i >= preorder.size()){
        return NULL;
    }

    if(preorder[i] < mini || preorder[i]>maxi){
        return NULL;
    }

    Node* root = new Node(preorder[i++]);

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;

    int i = 0;

    return solve(preorder, mini, maxi, i);
}

// Using only maxi
Node *solve2(vector<int> &preorder, int maxi, int &i) {
    if(i >= preorder.size() || preorder[i] > maxi){
        return NULL;
    }

    Node* root = new Node(preorder[i++]);

    root->left = solve2(preorder, root->data, i);
    root->right = solve2(preorder, maxi, i);

    return root;
}

Node* preorderToBST2(vector<int> &preorder) {
    int maxi = INT_MAX;
    int i = 0;

    return solve2(preorder, maxi, i);
}

int main(){
    // Node* root = NULL;
    // takeInput(root);
    // 50 20 70 10 30 90 110 -1
    
    vector<int> pre;
    pre.push_back(20);
    pre.push_back(10);
    pre.push_back(5);
    pre.push_back(15);
    pre.push_back(13);
    pre.push_back(35);
    pre.push_back(30);
    pre.push_back(42);

    Node* ans = preorderToBST(pre);
    levelOrderTraversal(ans);

    Node* ans2 = preorderToBST2(pre);
    levelOrderTraversal(ans2);
}