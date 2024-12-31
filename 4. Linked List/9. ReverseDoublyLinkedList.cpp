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

    // ~Node(){
    //     int val = this->data;
    //     if(next != NULL){
    //         delete next;
    //         next = NULL;
    //     }
    //     cout<<"Memory is free for data value "<<val<<endl;
    // }
};

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* ptr1 = head;
    Node* ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while(ptr2 != NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }  
    head = ptr1;
    return head;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node *node2 = new Node(11);
    node1->next = node2;
    node2->prev = node1;
    Node *head = node1;
    print(head);

    Node *head1 = reverse(head);
    print(head1);

}
