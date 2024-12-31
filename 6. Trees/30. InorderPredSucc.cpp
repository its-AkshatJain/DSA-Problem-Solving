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

// Inorder Predecessor Successor
// In an inorder traversal the number just smaller than the target is the 
// predecessor and the number just greater than the target is the successor. 
// T.C - O(n) and S.C - O(n)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Base case
        if(root == NULL){
            return ;
        }
        
        if(root->data == key){
            // Max element of left subtree is predecessor
            if(root->left != NULL){
                Node* temp = root->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                pre = temp;
            }
    
            // Min element of right subtree is successor
            if(root->right != NULL){
                Node* temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                suc = temp;
            }
            return ;
        }
        
        // Recursive call 
        if(root->data > key){
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }else{
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }


// T.C - O(n) and S.C - O(1)
pair<int, int> predecessorSuccessor(Node *root, int key){
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    // Finding Key Node
    while(temp && temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    if(temp != NULL){
        // Find Predeccessor
        Node* leftTree = temp->left;
        while(leftTree != NULL){
            pred = leftTree->data;
            leftTree = leftTree->right;
        }

        // Find Successor
        Node* rightTree = temp->right;
        while(rightTree != NULL){
            succ = rightTree->data;
            rightTree = rightTree->left;
        }
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1

    Node* predecessor = NULL;
    Node* successor = NULL;

    findPreSuc(root, predecessor, successor, 20);

    cout<<"Predecessor :"<<predecessor->data<<endl;
    cout<<"Successor :"<<successor->data<<endl;

    pair<int, int> ans = predecessorSuccessor(root,20);
    cout<<"Predecessor :"<<ans.first<<endl;
    cout<<"Successor :"<<ans.second<<endl;
}