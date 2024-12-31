#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node(){
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node *head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    // Write your code here
    int len = getLength(head);
    int mid = (len/2) + 1;
    Node* temp = head;
    int cnt = 1;
    while(cnt < mid){
        temp = temp->next;
        cnt++;
    }
    return temp;
}

// Optimised Approach
Node *findMiddle2(Node *head) {
    if(head == NULL && head->next == NULL){
        return head;
    }
    // if(head->next->next == NULL){
    //     return head->next;
    // }
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast !=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}


int main(){
    Node *node1 = new Node(10);
  
    Node *node2 = new Node(11);
    node1->next = node2;
    Node *head = node1;

    Node *node3 = new Node(12);
    node2->next = node3;
    print(head);

    // Node *middle = findMiddle(head);
    Node *middle = findMiddle2(head);
    cout<<"Middle Node is : "<<middle->data<<" "<<middle->next<<endl;
}