#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head == NULL && k<=1){
        return head;
    }

    Node* temp = head;
    int remLength = 0;
    // Calculating length for remaing list
    while(temp!=NULL && remLength < k){
        remLength++;
        temp = temp->next;
    }
    // If length is less than k, do not reverse
    if(remLength < k){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    // Step-1 reverse list in k grp for 1 case
    while(curr != NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step-2 recursion sab baki cases ke liye sambhal lega
    if(next != NULL){
        head->next = kReverse(next,k);
    }

    // Step-3 return head of the list
    return prev;
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
  
    Node *node2 = new Node(11);
    node1->next = node2;
    Node *head = node1;

    Node *node3 = new Node(12);
    node2->next = node3;

    Node *node4 = new Node(13);
    node3->next = node4;
    print(head);

    // Node *middle = findMiddle(head);
    Node *kreverse = kReverse(head,2);
    // cout<<"Middle Node is : "<<middle->data<<" "<<middle->next<<endl;
    print(kreverse);
}