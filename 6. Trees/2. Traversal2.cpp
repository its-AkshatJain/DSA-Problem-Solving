#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Implement inorder preorder and postorder without recursion

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

void inOrder(Node* root){
    if(root == NULL){
        return ;
    }

    stack<Node*> s;
    Node* current = root;

    while(!s.empty() || current != NULL){
        // Visit left nodes till last
        while(current != NULL){
            s.push(current);
            current = current->left;
        }

        // now current must be NULL
        current = s.top();
        s.pop();
        cout<<current->data<<" ";

        // Visit right nodes (as we have to visit right node one by one by backtracking
        // it will backtrack if current->right is NULL)
        current = current->right;
    }
    cout<<endl;
}

void preOrder(Node* root){
    if(root == NULL){
        return ;
    }

    stack<Node*> s;
    Node* current = root;

    while(!s.empty() || current != NULL){
        while(current != NULL){
            s.push(current);
            cout<<current->data<<" ";

            current = current->left;
        }
        
        current = s.top();
        current = current->right;
        s.pop();
    }
    cout<<endl;
}

void postOrder(Node* root){
    if(root == NULL){
        return ;
    }

    stack<Node*> s;
    Node* current = root;
    Node* lastVisited = NULL;

    while(!s.empty() || current != NULL){

        if(current!=NULL){
            s.push(current);
            current = current->left;
        }else{
            Node* peekNode = s.top();

            if(peekNode->right != NULL && lastVisited != peekNode->right){
                current = peekNode->right;
            }else{
                cout<<peekNode->data<<" ";
                lastVisited = s.top();
                s.pop();
            }
        }
    }
    cout<<endl;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"In-order Traversal is : "<<endl;
    inOrder(root);

    cout<<"Pre-order Traversal is : "<<endl;
    preOrder(root);

    cout<<"Post-order Traversal is : "<<endl;
    postOrder(root);
    
}