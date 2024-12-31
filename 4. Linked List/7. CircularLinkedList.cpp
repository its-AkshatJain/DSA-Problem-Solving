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

void insertNode(Node* &tail,int element,int d){
    // Empty List
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }else{
        // list is not empty
        // Assuming that the element is present in the List
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        // curr points at element
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail){

    if(tail == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){
    // Empty list
    if(tail == NULL){
        cout<<"List is empty ."<<endl;
        return ;
    }else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        // For 1 Node  linked List
        if(curr == prev){
            tail = NULL;
        }
        // For >=2 Node linked List
        if(tail == curr){
            tail = prev;
        }

        prev->next = curr->next;
        curr->next= NULL;
        delete curr;
    }
}

int main(){
    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,3,4);
    print(tail);

    deleteNode(tail,9);
    print(tail);
   
}