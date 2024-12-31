#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* reverse(Node *head){
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(struct Node* &head, struct Node* &tail, int digit){
    struct Node* temp = new Node(digit);
    if(head==NULL){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

struct Node* addDetailedForm(struct Node* num1, struct Node* num2){
    int carry = 0;
    struct Node* ansHead = NULL;
    struct Node* ansTail = NULL;
    
    while(num1 != NULL && num2 != NULL){
        int sum = carry + num1->data + num2->data;
        int digit = sum%10;
        carry = sum/10;
        
        insertAtTail(ansHead,ansTail,digit);
        num1 = num1->next;
        num2 = num2->next;
    }
    
    while(num1!=NULL){
        int sum = carry + num1->data;
        int digit = sum%10;
        carry = sum/10;
        
        insertAtTail(ansHead,ansTail,digit);
        num1 = num1->next;
    }
    
    while(num2!=NULL){
        int sum = carry + num2->data;
        int digit = sum%10;
        carry = sum/10;
        
        insertAtTail(ansHead,ansTail,digit);
        num2 = num2->next;
    }
    
    while(carry!=0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        
        insertAtTail(ansHead,ansTail,digit);
    }
    
    return ansHead;
}

struct Node* add(struct Node* num1, struct Node* num2){
    int carry = 0;
    struct Node* ansHead = NULL;
    struct Node* ansTail = NULL;
    
    while(num1 != NULL || num2 != NULL || carry!=0){

        int val1 = 0;
        if(num1 != NULL){
            val1 = num1->data;
            num1 = num1->next;
        }

        int val2 = 0;
        if(num2 != NULL){
            val2 = num2->data;
            num2 = num2->next;
        }

        int sum = carry + val1 + val2;
        int digit = sum%10;
        carry = sum/10;
        
        insertAtTail(ansHead,ansTail,digit);
        // num1 = num1->next;
        // num2 = num2->next;
    }    
    return ansHead;
}

struct Node* removeleadingZeros(struct Node* head){
    while(head != NULL && head->data == 0){
        struct Node* temp = head;
        head = head->next;
        delete temp;
    }
    if(head == NULL){
        return new Node(0);
    }
    return head;
}

struct Node* addTwoLists(struct Node* num1, struct Node* num2)
{
    // code here
    // Reverse the list
    num1 = reverse(num1);
    num2 = reverse(num2);
    
    // Add two numbers
    struct Node *ans = add(num1,num2);
    
    // reverse the ans
    ans = reverse(ans);
    
    // remove leading zeros
    ans = removeleadingZeros(ans);
    
    return ans;   
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
    struct Node *fnode1 = new Node(2);
  
    struct Node *fnode2 = new Node(0);
    fnode1->next = fnode2;
    Node *headf = fnode1;

    struct Node *fnode3 = new Node(0);
    fnode2->next = fnode3;
    print(headf);

    struct Node *snode1 = new Node(2);
  
    struct Node *snode2 = new Node(0);
    snode1->next = snode2;
    Node *heads = snode1;
    print(heads);

    struct Node* ans = addTwoLists(fnode1, snode1);
    print(ans);
}
