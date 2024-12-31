#include <iostream>
#include <vector>
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

void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void fillPreOrder(Node* root, vector<int> &in, int &index){
    if(root == NULL){
        return;
    }

    root->data = in[index++];
    fillPreOrder(root->left, in, index);
    fillPreOrder(root->right, in, index);
}

void convertToMinHeap(Node* root){
    vector<int> inOrder;
    int index = 0;

    // Creating inorder traversal
    inorder(root, inOrder);

    // Filling values in preorder
    fillPreOrder(root, inOrder, index);
}

// For max heap
void fillPostOrder(Node* root, vector<int> &in, int &index){
    if(root == NULL){
        return;
    }

    fillPostOrder(root->left, in, index);
    fillPostOrder(root->right, in, index);
    root->data = in[index++];
}

void convertToMaxHeap(Node* root){
    vector<int> inOrder;
    int index = 0;

    // Creating inorder traversal
    inorder(root, inOrder);

    // Filling values in preorder
    fillPostOrder(root, inOrder, index);
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 10 8 21 7 27 5 4 3 -1
    // 50 20 70 10 30 90 110 -1
    convertToMinHeap(root);

    cout << "Min Heap (Level Order Traversal):" << endl;
    levelOrderTraversal(root);

    convertToMaxHeap(root);
    cout << "Max Heap (Level Order Traversal):" << endl;
    levelOrderTraversal(root);
}

