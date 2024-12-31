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
};

// By replacing data values
Node* sortList(Node *head){
    // Write your code here.
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    // Counting 0s, 1s, 2s
    while(temp!=NULL){
        if(temp->data == 0){
            zeroCount++;
        }else if (temp->data == 1) {
            oneCount++;
        }else if (temp->data == 2) {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp!=NULL){
        if(zeroCount !=0){
            temp->data = 0;
            zeroCount--;
        }else if(oneCount !=0){
            temp->data = 1;
            oneCount--;
        }else if(twoCount !=0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

// Without replacing data values
void insertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList2(Node *head){
    // Write your code here.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    // Inserting data in different linked list
    while(curr!=NULL){
        int value = curr->data;
        if(value == 0){
            insertAtTail(zeroTail,curr);
        }else if(value == 1){
            insertAtTail(oneTail,curr);
        }else if(value == 2){
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }

    // Merge 3 sublist
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

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
    Node *node1 = new Node(2);
  
    Node *node2 = new Node(0);
    node1->next = node2;
    Node *head = node1;

    Node *node3 = new Node(1);
    node2->next = node3;

    Node *node4 = new Node(1);
    node3->next = node4;

    print(head);

    // Node* ans = sortList(head);
    Node* ans = sortList2(head);
    print(ans);
}