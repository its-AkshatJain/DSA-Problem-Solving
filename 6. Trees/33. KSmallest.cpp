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

int solve(Node* root, int &i, int k){
    if(root == NULL){
        return -1;
    }

    // L
    int left = solve(root->left, i, k);
    if(left != -1){
        return left;
    }

    // N
    i++;
    if(i == k){
        return root->data;
    }

    // R
    return solve(root->right, i, k);
}

int kthSmallest(Node* root, int k) {
    // Write your code here.
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

// Using morris traversal S.C O(n)
int kthSmallestMorris(Node* root, int k){
    if(root == NULL){
        return -1;
    }
    Node* curr = root;
    int i=0;
    while(curr!=NULL){
        // Case 1: if left is NULL
        if(curr->left == NULL){
            i++;
            if(i == k){
                return curr->data;
            }
            curr = curr->right;
        }else{
            // Case 2: if left is not NULL
            Node* prev = curr->left;
            
            // Now traverse till the last node of this path
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                // Creating temporary link
                prev->right = curr;
                curr = curr->left;
            }else{
                // if prev->right == curr;
                // Removing temporary link
                prev->right = NULL;
                i++;
                if(i == k){
                    return curr->data;
                }
                curr = curr->right;
            }
        }
    }
    return -1;
}

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right); 
}

//  for kth largest element
int kthLargest(Node* root, int k) {
    int n = countNodes(root);
    k = (n - k) + 1;
    int ans = kthSmallest(root, k);
    return ans;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1
    cout<<"Kth smallest element of BST is : "<<kthSmallest(root, 3)<<endl;
    // cout<<"Kth smallest element of BST is (Morris): "<<kthSmallestMorris(root, 3)<<endl;
    cout<<"Kth largest element of BST is : "<<kthLargest(root, 3)<<endl;
}