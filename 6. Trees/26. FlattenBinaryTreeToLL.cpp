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

void flatten(Node* &root){
    Node* curr = root;

    while(curr!=NULL){
        if(curr->left){
            Node* prev = curr->left;

            while(prev->right){
                prev = prev->right;
            }

            // We are setting it to curr ka right 
            prev->right = curr->right;
            curr->right = curr->left;
            // As we want to make all left pointer as null
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printFlattenedTree(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}


int main(){
    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    flatten(root);
    printFlattenedTree(root);
}