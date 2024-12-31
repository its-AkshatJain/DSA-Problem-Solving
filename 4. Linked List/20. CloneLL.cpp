#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

// Clone a linked list with next and random pointer

void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return ; 
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

// TC - O(n)  SC - O(n)
Node *copyList(Node *head)
{
    //Write your code here
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    Node* temp = head;
    // Step 1 Copying List using next pointer
    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    
    // Step 2 Create a mapping of oldToNew node
    unordered_map<Node*,Node*> oldToNewNode;
    Node* oldNode = head;
    Node* cloneNode = cloneHead;
    while(oldNode!=NULL){
        oldToNewNode[oldNode] = cloneNode;
        oldNode = oldNode->next;
        cloneNode = cloneNode->next;
    }
    
    oldNode = head;
    cloneNode = cloneHead;
    // Adding values of random pointer on clone linked list
    while(oldNode!=NULL){
        cloneNode->random = oldToNewNode[oldNode->random];
        oldNode = oldNode->next;
        cloneNode = cloneNode->next;
    }
    
    return cloneHead;
}


// TC - O(n)  SC - O(1)
Node *copyList2(Node *head)
    {
        //Write your code here
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        // Step 1 Creating clone list Copying List using next pointer
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // Step 2 Add clone nodes in between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL ){
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
     
        // Step 3 Copying random pointer to the clone list
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random ? temp->random->next : NULL;
            }
            temp = temp->next->next;
            
        }
      

        // Step 4 revert the step 2
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL ){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode!=NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
            
        }
        // Step 5 
        return cloneHead;
    }

void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    Node *node1 = new Node(12);
    Node *head = node1;

    Node *node2 = new Node(80);
    node1->next = node2;

    Node *node3 = new Node(124);
    node2->next = node3;
    
    Node *node4 = new Node(75);
    node3->next = node4;
    
    node1->random = node3;
    node2->random = node4;
    node3->random = node1;
    node4->random = node2;

    print(head);

    // Node* ans = copyList(head);
    Node* ans = copyList2(head);
    print(ans);
}