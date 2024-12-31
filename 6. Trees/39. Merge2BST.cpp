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

void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeSortedArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int i=0, j=0;
    int k=0;

    while(i<a.size() && j<b.size()){
        if(a[i] <= b[j]){
            ans[k++] = a[i];
            i++;
        }else{
            ans[k++] = b[j];
            j++;
        }
    }

    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }

    while(j < b.size()){
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

Node* inorderToBST(int s, int e, vector<int> &in){
    // Base case
    if(s>e){
        return NULL;
    }

    int mid = s + (e - s)/2;
    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);

    return root;

}
// For returning merged BST  S.C - O(m+n)
Node* mergeBST(Node *root1, Node *root2)
{
    // Step 1 : find inorder of both bst and store in array
    vector<int> bst1;
    vector<int> bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Step 2: Merge Two Sorted Array
    vector<int> mergeArray = mergeSortedArrays(bst1, bst2);

    // Step 3: Inorder to BST
    return inorderToBST(0, mergeArray.size()-1, mergeArray);
}

// For returning merged inorder vector
vector<int> mergeBST2(Node *root1, Node *root2)
{
    // Step 1 : find inorder of both bst and store in array
    vector<int> bst1;
    vector<int> bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Step 2: Merge Two Sorted Array
    vector<int> mergeArray = mergeSortedArrays(bst1, bst2);

    // Step 3: Inorder to BST
    return mergeArray;
}

// Now using S.C- O(h1+h2)
void convertIntoSortedDLL(Node* root, Node* &head){
    // Base case
    if(root == NULL){
        return ;
    }

    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if(head!=NULL){
        head->left = root;
    }

    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node* mergeSortedLinkedList(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail = NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1!=NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2!=NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedLLToBST(Node* &head, int n){
    // Base case
    if(n<= 0 || head == NULL){
        return NULL;
    }

    Node* left = sortedLLToBST(head, n/2);

    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n - n/2 - 1);

    return root;
}

Node* mergeBST3(Node *root1, Node *root2)
{
    // Step 1 : find inorder of both bst and store in a linked list
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // Step 2: Merge Two Sorted Array
    Node* head = mergeSortedLinkedList(head1, head2);

    // Step 3: Inorder to BST
    return sortedLLToBST(head, countNodes(head));
}

int main(){
    cout<<"Enter first BST : "<<endl;
    Node* root1 = NULL;
    takeInput(root1);
    // 50 20 70 10 30 90 110 -1

    cout<<"Enter second BST : "<<endl;
    Node* root2 = NULL;
    takeInput(root2);
    // 20 10 5 15 13 35 30 42 -1
    
    Node* ans1 = mergeBST(root1,root2);
    levelOrderTraversal(ans1);

    vector<int> ans2 = mergeBST2(root1,root2);
    for(auto i: ans2){
        cout<<i<<" ";
    }
    cout<<endl;

    Node* ans3 = mergeBST3(root1,root2);
    levelOrderTraversal(ans3);
}