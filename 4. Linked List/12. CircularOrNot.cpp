#include <iostream>
#include <map>
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

bool isCircularList(Node* head){
    // for empty List
    if(head == NULL){
        return true;
    }
    // this case will be handled by >1 Node case
    // if(head->next == NULL){
    //     return false;
    // }
    Node* temp = head->next;
    // Check list is circular or not
    while(temp!= head && temp!=NULL){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

// Using Map
bool isCircularList2(Node* head){
    // for empty List
    if(head == NULL){
        return true;
    }
    map<Node*, bool> m;
    Node* temp = head;
    // Check list is circular or not
    while(m[temp] != true && temp!=NULL){
        m[temp] = true;  // marking node as visited
        temp = temp->next;
    }
    if(m[temp] == true){
        return true;
    }
    return false;
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
    cout<<"Is circular or not : "<<isCircularList2(head)<<endl;
}