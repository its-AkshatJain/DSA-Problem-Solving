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

// Detect Loops
bool detectLoop(Node* head){
    // for empty List
    if(head == NULL){
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;

    while(temp!=NULL){
        if(visited[temp] == true){
            cout<<endl<<"Present on element : "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;  // marking node as visited
        temp = temp->next;
    }
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL; 
}

// Get Starting / Beginning of loop
Node *getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Remove Loop
Node* removeLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* startingOfLoop = getStartingNode(head);
    Node* temp = startingOfLoop;
    while(temp->next != startingOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
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
    }while(temp != head);
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

    node4->next = node2;
    // print(head);  // for circular list printing

    cout<<"Is there loop in linked list or not : "<<detectLoop(head)<<endl;
    Node* ans = floydDetectLoop(head);
    cout<<"Loop is detected at : "<<ans->data<<endl;

    Node* startingNode = getStartingNode(head);
    cout<<"Starting node of loop is : "<<startingNode->data<<endl;

    Node* noLoop = removeLoop(head);
    // print(noLoop);
}