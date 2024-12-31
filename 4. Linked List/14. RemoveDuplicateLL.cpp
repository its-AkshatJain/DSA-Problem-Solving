#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int data)
        {
        this->data = data;
        this->next = NULL;
        }
};

class NodeD {
 public:
      int data;
      NodeD *prev;
      NodeD *next;
      NodeD() {
          this->data = 0;
          this->prev = NULL;
          this->next = NULL;
      }
      NodeD(int data) {
          this->data = data;
          this->prev = NULL;
          this->next = NULL;
      }
      NodeD (int data, NodeD *next, NodeD *prev) {
          this->data = data;
          this->prev = prev;
          this->next = next;
      }
 };

// Remove Duplicate from sorted Singly linked List
Node * removeDuplicates(Node *head)
{
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr->data == curr->next->data){
            // Equal
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;

            delete nodeToDelete;

            curr->next = next_next;
            // delete nodeToDelete;  
        }else{
            // Not equal
            curr = curr->next;
        }
    }
    return head;
}

// Remove Duplicate from sorted Doubly linked List
NodeD * removeDuplicatesDoubly(NodeD *head)
{
    // Write your code here
    if(head == NULL){
        return NULL;
    }
    NodeD* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr->data == curr->next->data){
            // Equal
            NodeD* next_next = curr->next->next;
            NodeD* nodeToDelete = curr->next;

            delete nodeToDelete;

            curr->next = next_next;
            if(next_next != NULL){
                next_next->prev = curr;
            }
            // delete nodeToDelete;
            
        }else{
            // Not equal
            curr = curr->next;
        }
    }
    return head;
}

// Remove Duplicate from Unsorted Singly linked List
// Using map
Node * removeDuplicatesUnsorted(Node *head)
{
    if(head==NULL){
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    map<int,bool> visited;

    while(curr!=NULL){
        if(visited[curr->data] == true){
            Node* nodeToDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete nodeToDelete;
        }else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }     
    }
    return head;
}

// Using Unordered Set
Node * removeDuplicatesUnsorted2(Node *head)
{
    if(head==NULL){
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    map<int,bool> visited;

    while(curr!=NULL){
        if(visited[curr->data] == true){
            Node* nodeToDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete nodeToDelete;
        }else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }     
    }
    return head;
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
    Node *node1 = new Node(10);
  
    Node *node2 = new Node(13);
    node1->next = node2;
    Node *head = node1;

    Node *node3 = new Node(12);
    node2->next = node3;

    Node *node4 = new Node(13);
    node3->next = node4;

    print(head);

    // Node* ans = removeDuplicates(head);
    Node* ans = removeDuplicatesUnsorted2(head);
    print(ans);

}