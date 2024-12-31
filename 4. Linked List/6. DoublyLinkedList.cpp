#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for data value "<<val<<endl;
    }
};

// Traversing doubly linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Finding length of doubly linked list
int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int d){
    // For empty node
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        // Create a node
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int d){
    // For empty node
    if(tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        // Create a node
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position == 1){
        insertAtHead(head,tail,d);
        return ; 
    }
    Node* temp = head;
    int cnt = 1;
    if(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return ;
    }

    // create a node
    Node* nodetoInsert = new Node(d);

    nodetoInsert->prev = temp;
    nodetoInsert->next = temp->next;
    temp->next->prev = nodetoInsert;
    temp->next = nodetoInsert;
}


void deleteNode(int position,Node* &head,Node* &tail){
    if(position == 1){
        // deleting start node
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        // deleting middle or last node
        Node* prev = NULL;
        Node* curr = head;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->next->prev = prev;
        prev->next = curr->next;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
        if(prev->next == NULL){
            tail = prev;
        }
    }
}


int main(){
    // Node *node1 = new Node(5);
    // Node* head = node1;
    // Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    cout<<"Length is : "<<getLength(head)<<endl;

    insertAtHead(head,tail,10);
    print(head);
    cout<<"Length is : "<<getLength(head)<<endl;

    insertAtTail(head,tail,25);
    print(head);

    insertAtPosition(head,tail,3,15);
    print(head);

    deleteNode(2,head,tail);
    print(head);
    cout<<tail->data;

}