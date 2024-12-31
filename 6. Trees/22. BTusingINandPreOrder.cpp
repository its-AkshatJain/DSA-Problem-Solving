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

int findPosition(int in[],int inOrderStart, int inOrderEnd, int element){
    for(int i=inOrderStart; i<=inOrderEnd; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[],int pre[], int n, int &index, 
            int inOrderStart, int inOrderEnd){
    // Base case
    if(index >= n || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    // Create a root node
    int element = pre[index++];
    Node* root = new Node(element);
    // Find its position in inOrder
    int position = findPosition(in, inOrderStart, inOrderEnd, element);
    
    // recursive calls
    root->left = solve(in, pre, n, index, inOrderStart, position-1);
    root->right = solve(in, pre, n, index, position+1, inOrderEnd);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    
    Node* ans = solve(in, pre, n, preOrderIndex, 0, n-1);
    return ans;
}

// Optimised Using map but not submitted on gfg due to updated test case
void createMapping(int in[],int n, map<int,int> &nodeToIndex){
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve2(int in[],int pre[], int n, int &index, 
            int inOrderStart, int inOrderEnd, map<int,int> &nodeToIndex){
    // Base case
    if(index >= n || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    // Create a root node
    int element = pre[index++];
    Node* root = new Node(element);
    // Find its position in inOrder
    int position = nodeToIndex[element];
    
    // recursive calls
    root->left = solve2(in, pre, n, index, inOrderStart, position-1, nodeToIndex);
    root->right = solve2(in, pre, n, index, position+1, inOrderEnd, nodeToIndex);
    
    return root;
}

Node* buildTree2(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    map<int,int> nodeToIndex;
    
    // create nodes to index mapping
    createMapping(in,n,nodeToIndex);
    
    Node* ans = solve2(in, pre, n, preOrderIndex, 0, n-1, nodeToIndex);
    return ans;
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
    int inOrder[] = {1, 6, 8, 7};
    int preOrder[] = {1, 6, 7, 8};

    Node* ans = buildTree(inOrder,preOrder,4);
    postOrder(ans);
    cout<<endl;
    Node* ans2 = buildTree2(inOrder,preOrder,4);
    postOrder(ans2);
}