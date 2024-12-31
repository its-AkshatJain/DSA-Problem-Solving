#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


Node<int>* solve(Node<int>* first, Node<int>* second){

    if(first->next == NULL){
        first->next = second;
        return first;
    }

    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;

    while((next1 != NULL) && (curr2 != NULL)){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            // Inserting node between curr1 and next1
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // Updating pointer
            curr1 = curr2;
            curr2 = next2;
        }else{
            // curr1 or next1 pointer ko aage badhana
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    if(first->data <= second->data){
        return solve(first,second);
    }else{
        return solve(second,first);
    }
}

void print(Node<int>* &head){
    Node<int> *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node<int> *fnode1 = new Node<int>(1);
  
    Node<int> *fnode2 = new Node<int>(3);
    fnode1->next = fnode2;
    // Node<int> *head = node1;

    Node<int> *fnode3 = new Node<int>(5);
    fnode2->next = fnode3;

    Node<int> *fnode4 = new Node<int>(9);
    fnode3->next = fnode4;

    Node<int> *snode1 = new Node<int>(2);
  
    Node<int> *snode2 = new Node<int>(4);
    snode1->next = snode2;
    // Node<int> *head2 = snode1;

    Node<int> *snode3 = new Node<int>(5);
    snode2->next = snode3;

    Node<int> *snode4 = new Node<int>(8);
    snode3->next = snode4;

    print(fnode1);
    print(snode1);

    // Node* ans = sortList(head);
    Node<int>* ans = sortTwoLists(fnode1,snode1);
    print(ans);
}