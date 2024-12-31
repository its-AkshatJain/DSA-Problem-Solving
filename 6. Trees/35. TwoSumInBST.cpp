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

void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(Node* root, int target) {
	vector<int> inorderVal;
    // Store inorder
    inorder(root, inorderVal);

    // Use 2 pointer aproch to find target
    int i = 0, j = inorderVal.size() - 1;
    
    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target){
            return true;
        }else if(sum > target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1

    cout<<"Two sum is present in BST or not for 50 : "<<twoSumInBST(root, 50);
}