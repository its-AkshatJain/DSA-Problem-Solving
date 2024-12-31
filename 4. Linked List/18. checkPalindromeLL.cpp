#include <iostream>
#include <vector>
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

// Using extra space as array
bool checkPalindrome(vector<int> arr){
       int s = 0;
       int e = arr.size()-1;
       while(s<=e){
           if(arr[s] != arr[e]){
               return 0;
           }
           s++;
           e--;
       }
       return 1;
   }

bool isPalindrome(Node *head){
    vector<int> arr;
    
    // Copying Linked list to an array
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    
    return checkPalindrome(arr);
}

// Without using extra space
Node* getMid(Node *head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node *head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
  
bool isPalindrome2(Node *head)
{
    //Your code here
    if(head== NULL && head->next == NULL){
        return true;
    }
    // Step 1 get middle
    Node* middle = getMid(head);
    
    // Step 2 reverse the List after middle
    Node* temp = middle->next;
    middle->next = reverse(temp);
    
    // Step3 Compare both the halves
    Node* head1 = head;
    Node* head2 = middle->next;
    
    while(head2!=NULL){
        if(head1->data != head2->data){
            // Step 4 reverse the list back
            temp = middle->next;
            middle->next = reverse(temp);
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // Step 4 reverse the list back
    temp = middle->next;
    middle->next = reverse(temp);
    
    return true;
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

    Node *node3 = new Node(0);
    node2->next = node3;

    Node *node4 = new Node(2);
    node3->next = node4;

    print(head);

    cout<<"Linked list is Palindrome or Not : "<<isPalindrome(head)<<endl;
    cout<<"Linked list is Palindrome or Not : "<<isPalindrome2(head)<<endl;

}
