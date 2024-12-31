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

int findPosition(int in[],int inOrderStart, int inOrderEnd,int element){
    for(int i=inOrderStart; i<=inOrderEnd; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[],int post[], int n, int &index, 
            int inOrderStart, int inOrderEnd){
    // Base case
    if(index < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    // Create a root node
    int element = post[index--];
    Node* root = new Node(element);
    // Find its position in inOrder
    int position = findPosition(in, inOrderStart, inOrderEnd, element);
    
    // recursive calls (in case of inorder and postorder we first build right subtree)
    root->right = solve(in, post, n, index, position+1, inOrderEnd);
    root->left = solve(in, post, n, index, inOrderStart, position-1);
    
    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int n, int in[], int post[]) {
    int postOrderIndex = n-1;
    
    Node* ans = solve(in, post, n, postOrderIndex, 0, n-1);
    return ans;
}

// Optimised Using map but not submitted on gfg due to updated test case
void createMapping(int in[],int n, map<int,int> &nodeToIndex){
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve2(int in[],int post[], int n, int &index, 
            int inOrderStart, int inOrderEnd, map<int,int> &nodeToIndex){
    // Base case
    if(index < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    // Create a root node
    int element = post[index--];
    Node* root = new Node(element);
    // Find its position in inOrder
    int position = nodeToIndex[element];
    
    // recursive calls
    root->right = solve2(in, post, n, index, position+1, inOrderEnd, nodeToIndex);
    root->left = solve2(in, post, n, index, inOrderStart, position-1, nodeToIndex);
    
    return root;
}

Node* buildTree2(int n, int in[],int post[])
{
    int postOrderIndex = n-1;
    map<int,int> nodeToIndex;
    
    // create nodes to index mapping
    createMapping(in,n,nodeToIndex);
    
    Node* ans = solve2(in, post, n, postOrderIndex, 0, n-1, nodeToIndex);
    return ans;
}

// PreOrder Traversal
void preOrder(Node* root){
    if(root == NULL){
        return ;
    }
    // PreOrder LRN
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int inOrder[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postOrder[] = {8, 4, 5, 2, 6, 7, 3, 1};

    Node* ans = buildTree(8, inOrder, postOrder);
    preOrder(ans);
    cout<<endl;
    Node* ans2 = buildTree2(8, inOrder, postOrder);
    preOrder(ans2);
}