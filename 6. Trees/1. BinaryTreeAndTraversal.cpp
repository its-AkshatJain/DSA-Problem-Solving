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

void buildFromLevelOrderTraversal(Node* &root){
    queue<Node*> q;
    int data;
    cout<<"Enter the data of root node : "<<endl;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter the data for left node of "<<temp->data<<" : "<<endl;
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter the data for right node of "<<temp->data<<" : "<<endl;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // Purana level fully traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){
                // Still queue has some child nodes
                q.push(NULL);   // it will we added at back of queue and we are accessing elements from front
            }
        }else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// Reverse Level Order Traversal
void reverseLevelOrderTraversal(Node * root){
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        s.push(temp);

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        if(temp == NULL){
            cout<<endl;
        }else{
            cout<<temp->data<<" ";
        }
    }
    cout<<endl;
}

// InOrder Traversal
void inOrder(Node* root){
    if(root == NULL){
        return ;
    }
    // Inorder LNR
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// PreOrder Traversal
void preOrder(Node* root){
    if(root == NULL){
        return ;
    }
    // Preorder NLR
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// PostOrder Traversal
void postOrder(Node* root){
    if(root == NULL){
        return ;
    }
    // PostOrder LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    levelOrderTraversal(root);

    reverseLevelOrderTraversal(root);

    cout<<"In-order Traversal is : "<<endl;
    inOrder(root);
    cout<<endl;

    cout<<"Pre-order Traversal is : "<<endl;
    preOrder(root);
    cout<<endl;

    cout<<"Post-order Traversal is : "<<endl;
    postOrder(root);
    cout<<endl;

    Node* root1 = NULL;
    buildFromLevelOrderTraversal(root1);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTraversal(root1);

    return 0;
}