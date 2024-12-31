#include <iostream>
#include <unordered_map>
using namespace std;

class node{
    public:
    int data;
    node* next;
    

    // Constructor
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

node* getMid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    
    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL){
        return head;
    }
    // Dividing list into two halves
    node* mid = getMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // Sort Left and right
    left = mergeSort(left);
    right = mergeSort(right);

    // merge sorted linked list
    node* result = merge(left,right);
    return result;  
}

void print(node* &head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    node *node1 = new node(12);
    node *head = node1;

    node *node2 = new node(80);
    node1->next = node2;

    node *node3 = new node(124);
    node2->next = node3;
    
    node *node4 = new node(75);
    node3->next = node4;
    

    print(head);


    node* ans = mergeSort(head);
    print(ans);
}