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

// Insert at start/Head
void insertAtHead(Node* &head,int d){
    // create new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert at tail/ End 
void insertAtTail(Node* &tail,int d){
    // create new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp; 
}

// Insert at middle/between/positin
void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    // Insert at start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    // Insert at end
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    // create a node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


void deletenode(Node* &head,Node* &tail,int position){
    if(position == 1){
        // deleting start node
        Node* temp = head;
        head = head->next;
        temp->next =NULL;
        delete temp;
    }else{
        // deleting middle or last node
        int cnt = 1;
        Node* prev = NULL;
        Node* curr = head;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if(prev->next == NULL){
            tail = prev;
            // return;
        }
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,20);
    print(head);
    insertAtTail(tail,5);
    print(head);

    insertAtPosition(head,tail,3,12);
    print(head);
    insertAtPosition(head,tail,1,11);
    print(head);

    cout<<head->data<<"    "<<tail->data<<endl;
    deletenode(head,tail,5);
    print(head);
    cout<<head->data<<"    "<<tail->data<<endl;
}