#include <iostream>
#include <queue>
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

// Insertion Using Recursion
Node* insertion(Node* &root,int d){
    // Base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(root->data == d){
        return root;
    }

    if(root->data > d){
        root->left = insertion(root->left,d);
    }

    if(root->data < d){
        root->right = insertion(root->right,d);
    }

    return root;
    
}

// Insertion Using Iteration
Node* insertionUsingIteration( Node* &root, int d){
    Node* temp = new Node(d);
    if(root == NULL){
        root = temp;
        return root;
    }

    Node* parent = NULL;
    Node* curr = root;
    // Moving curr to the correct postion of insertion
    while(curr!=NULL){
        parent = curr;
        if(curr->data > d){
            curr = curr->left;
        }else if(curr->data < d){
            curr = curr->right;
        }else {
            // If the data already exists, no need to insert
            delete temp;
            return root;
        }
    }

    // Check value of parent data and make new node left/right child
    if(parent->data > d){
        parent->left = temp;
    }else{
        // if parent->data < d
        parent->right = temp;
    }

    return root;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 10 8 21 7 27 5 4 3 -1
    levelOrderTraversal(root);

    cout<<"In-order Traversal is : "<<endl;
    inOrder(root);
    cout<<endl;

    cout<<"Pre-order Traversal is : "<<endl;
    preOrder(root);
    cout<<endl;

    cout<<"Post-order Traversal is : "<<endl;
    postOrder(root);
    cout<<endl;

    root = insertion(root,23);
    levelOrderTraversal(root);
    
    root = insertionUsingIteration(root,28);
    levelOrderTraversal(root);
}