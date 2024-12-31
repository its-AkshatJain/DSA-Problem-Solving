#include <iostream>
using namespace std;

template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

void print(LinkedListNode<int>* &head){
    LinkedListNode<int> *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL){
        return head;
        // print(head);
    }
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    // print(prev);
    return prev;
}

// recursive approach   TC - O(n) , SC - O(n)
LinkedListNode<int>* reverse1(LinkedListNode<int>* head) 
{
    // Base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    // Recursion will reverse and find the head for small list
    LinkedListNode<int>* chotaHead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

void reverse2rec(LinkedListNode<int>* &head,LinkedListNode<int>* curr,LinkedListNode<int>* prev)
{
    // Base case
    if(curr == NULL){
        head = prev;
        return;
    }

    LinkedListNode<int> *forward = curr->next;
    reverse2rec(head,forward,curr);
    curr->next = prev;
}

LinkedListNode<int>* reverse2(LinkedListNode<int>* head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL){
        return head;
        // print(head);
    }
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    reverse2rec(head,curr,prev);
    return head;
}

int main(){
    LinkedListNode<int> *node1 = new LinkedListNode<int>(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    LinkedListNode<int> *node2 = new LinkedListNode<int>(11);
    node1->next = node2;
    LinkedListNode<int> *head = node1;
    print(head);

    // LinkedListNode<int> *head1 = reverseLinkedList(head);
    // print(head1);

    // LinkedListNode<int> *head2 = reverse1(head);
    // print(head2);

    LinkedListNode<int> *head3 = reverse1(head);
    print(head3);

    

}