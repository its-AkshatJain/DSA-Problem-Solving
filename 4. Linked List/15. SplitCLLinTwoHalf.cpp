#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int d){
        this->data=d;
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

int getLength(Node* head){
    if(head==NULL){
        return 0;
    }
    int len = 1;
    if(head->next != NULL){
        Node* temp = head->next;
        while(temp != head){
            len++;
            temp = temp->next;
        }
    }
    return len;
}

void print(Node* head){

    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(head != temp);
    cout<<endl;
}

// Split Circular linked List into two circular halves
void splitCircularList(Node* head){
    if(head==NULL || head->next == head){
        cout<<"Cannot split circular list which is null or has single node "<<endl;
    }else{
        int length = getLength(head);
        int mid =  length/2;

        int cnt = 1;
        Node* temp = head;
        while(cnt < mid){
            cnt++;
            temp = temp->next;
        }
        Node* L1 = head;
        Node* L2 = temp->next;
        Node* temp2 = L2;
        temp->next = L1;
        while(temp2->next != head){
            temp2 = temp2->next;
        }
        temp2->next = L2;
        cout<<"Two halves of circular linked list which are circular are :"<<endl;
        print(L1);
        print(L2);
    }
}

int main(){
    Node *node1 = new Node(10);
  
    Node *node2 = new Node(11);
    node1->next = node2;
    Node *head = node1;

    Node *node3 = new Node(12);
    node2->next = node3;

    Node *node4 = new Node(13);
    node3->next = node4;

    node4->next = node1;
    print(head);  // for circular list printing

    // cout<<"Is circular or not : "<<isCircularList(head)<<endl;
    cout<<"Length is : "<<getLength(head)<<endl;
    splitCircularList(head);
}